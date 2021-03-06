/*

2.4 kbps MELP Proposed Federal Standard speech coder

version 1.2

Copyright (c) 1996, Texas Instruments, Inc.  

Texas Instruments has intellectual property rights on the MELP
algorithm.  The Texas Instruments contact for licensing issues for
commercial and non-government use is William Gordon, Director,
Government Contracts, Texas Instruments Incorporated, Semiconductor
Group (phone 972 480 7442).


*/

/*                                                                  */
/*  melp.c: Mixed Excitation LPC speech coder                       */
/*                                                                  */

/*  compiler include files  */
#include <stdio.h>
#include "melp.h"
#include "spbstd.h"
#include "mat.h"
#include "dsp_sub.h"
#include "melp_sub.h"

/* note: CHSIZE is shortest integer number of words in channel packet */
#define CHSIZE 9
#define NUM_CH_BITS 54



#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//#include "sc1200.h"
//#include "mat_lib.h"
//#include "global.h"
//#include "macro.h"
//#include "mathhalf.h"
//#include "dsp_sub.h"
//#include "melp_sub.h"
//#include "constant.h"
//#include "math_lib.h"
//#include "math.h"
//#include "transcode.h"

/* ====== External memory ====== */

#define FRAME				180              /* speech frame size */
#define NF					3                /* number of frames in one block */
#define BLOCK				(NF*FRAME)

typedef unsigned short uint16_t;
typedef signed short int16_t;

int		mode;
int		rate;

/* ========== Static Variables ========== */

char in_name[256], out_name[256];
struct melp_param	melp_ana_par;                 /* melp analysis parameters */
struct melp_param	melp_syn_par;                 /* melp synthesis parameters */

/* ========== Local Private Prototypes ========== */

static void		parseCommandLine(int argc, char *argv[]);
static void		printHelpMessage(char *argv[]);

static char *cmd_line[] = {"melp", "-i", "test_in.raw", "-o", "test_out.raw", 0};

extern int main_cmd(int argc, char *argv[]);

#define MAXSIZE 1024
#define SIGMAX 32767
typedef int16_t SPEECH;

SPEECH	int_sp[MAXSIZE]; /*  integer input array	*/

/*								*/
/*	Subroutine READBL: read block of input data		*/
/*								*/
int readbl(float input[], FILE *fp_in, int size)
{
	int i, length;

	length = fread(int_sp,sizeof(SPEECH),size,fp_in);
	for (i = 0; i < length; i++ )
		input[i] = (float) int_sp[i];
	for (i = length; i < size; i++ )
		input[i] = 0.0f;

	return length;
}

/*								*/
/*	Subroutine WRITEBL: write block of output data		*/
/*								*/
void writebl(float output[], FILE *fp_out, int size)

{
	int i;
	float temp;

	for (i = 0; i < size; i++ ) {
		temp = output[i];
		/* clamp to +- SIGMAX */
		if (temp > SIGMAX)	  temp = SIGMAX;
		if (temp < -SIGMAX)	  temp = -SIGMAX;
		int_sp[i] = (SPEECH)temp;
	}
	fwrite(int_sp,sizeof(SPEECH),size,fp_out);
}


int main()
{
	main_cmd(5, cmd_line);
}

/****************************************************************************
**
** Function:        main
**
** Description:     The main function of the speech coder
**
** Arguments:
**
**  int     argc    ---- number of command line parameters
**  char    *argv[] ---- command line parameters
**
** Return value:    None
**
*****************************************************************************/
int main_cmd(int argc, char *argv[])
{
	int	length;
	int frame_count;

	float	speech_in[BLOCK], speech_out[BLOCK];
	int		eof_reached = FALSE;
	FILE	*fp_in, *fp_out;

	/* ====== Get input parameters from command line ====== */
	parseCommandLine(argc, argv);

	/* ====== Open input, output, and parameter files ====== */
	if ((fp_in = fopen(in_name,"rb")) == NULL){
		fprintf(stderr, "  ERROR: cannot read file %s.\n", in_name);
		exit(1);
	}
	if ((fp_out = fopen(out_name,"wb")) == NULL){
		fprintf(stderr, "  ERROR: cannot write file %s.\n", out_name);
		fclose(fp_in);
		exit(1);
	}

	/* ====== Initialize MELP analysis and synthesis ====== */
	melp_ana_init(&melp_ana_par);
	melp_syn_init(&melp_syn_par);

	/* ====== Run MELP coder on input signal ====== */
	frame_count = 0;
	eof_reached = FALSE;
	while (!eof_reached)
	{
		fprintf(stderr, "Frame = %ld\r", frame_count);

		/* Perform MELP analysis */
		length = readbl(speech_in, fp_in, FRAME);
		if (length < FRAME){
			eof_reached = TRUE;
		}
		melp_ana(speech_in, &melp_ana_par);

		/* Perform MELP synthesis */
		melp_syn(&melp_syn_par, speech_out);
		writebl(speech_out, fp_out, FRAME);
		frame_count++;
	}

	fclose(fp_in);
	fclose(fp_out);
	fprintf(stderr, "\n\n");

	return(0);
}


/****************************************************************************
**
** Function:        parseCommandLine
**
** Description:     Translate command line parameters
**
** Arguments:
**
**  int     argc    ---- number of command line parameters
**  char    *argv[] ---- command line parameters
**
** Return value:    None
**
*****************************************************************************/
static void		parseCommandLine(int argc, char *argv[])
{
	int16_t	i;
	int		error_flag = FALSE;

	if (argc < 2)
		error_flag = TRUE;

	/* Setting default values. */
	mode = ANA_SYN;
	rate = RATE2400;
	in_name[0] = '\0';
	out_name[0] = '\0';

	for (i = 1; i < argc; i++){
		if ((strncmp(argv[i], "-h", 2 ) == 0) ||
			(strncmp(argv[i], "-help", 5) == 0)){
			printHelpMessage(argv);
			exit(0);
		} else if ((strncmp(argv[i], "-a", 2)) == 0)
			mode = ANALYSIS;
		else if ((strncmp(argv[i], "-s", 2)) == 0)
			mode = SYNTHESIS;
		else if ((strncmp(argv[i], "-i", 2)) == 0){
			i++;
			if (i < argc)
				strcpy(in_name, argv[i]);
			else
				error_flag = TRUE;
		} else if ((strncmp(argv[i], "-o", 2)) == 0){
			i++;
			if (i < argc)
				strcpy(out_name, argv[i]);
			else
				error_flag = TRUE;
		} else
			error_flag = TRUE;
	}

	if ((in_name[0] == '\0') || (out_name[0] == '\0'))
		error_flag = TRUE;

	if (error_flag){
		printHelpMessage(argv);
		exit(1);
	}
	switch (mode){
	case ANA_SYN:
	case ANALYSIS:
	case SYNTHESIS:
		if (rate == RATE2400)
			fprintf(stderr, " ---- 2.4kbps mode.\n");
		else
			fprintf(stderr, " ---- 1.2kbps mode.\n");
		break;
	}
	switch (mode){
	case ANA_SYN:
		fprintf(stderr, " ---- Analysis and Synthesis.\n"); break;
	case ANALYSIS:
		fprintf(stderr, " ---- Analysis only.\n"); break;
	case SYNTHESIS:
		fprintf(stderr, " ---- Synthesis only.\n"); break;
	}

	fprintf(stderr, " ---- input from %s.\n", in_name);
	fprintf(stderr, " ---- output to %s.\n", out_name);
}


/****************************************************************************
**
** Function:        printHelpMessage
**
** Description:     Print Command Line Usage
**
** Arguments:
**
** Return value:    None
**
*****************************************************************************/
static void		printHelpMessage(char *argv[])
{
	fprintf(stdout, "Usage:\n");
	fprintf(stdout, "\t%s [-as] -i infile -o outfile\n", argv[0]);
	fprintf(stdout, "\t\tdefault: Analysis/Synthesis at 2.4kbps\n");
	fprintf(stdout, "\t\t-a --analysis\tAnalysis only\n");
	fprintf(stdout, "\t\t-s --synthesis\tSynthesis only\n\n");
}
