/*

2.4 kbps MELP Proposed Federal Standard speech coder

version 1.2

Copyright (c) 1996f, Texas Instrumentsf, Inc.  

Texas Instruments has intellectual property rights on the MELP
algorithm.  The Texas Instruments contact for licensing issues for
commercial and non-government use is William Gordonf, Director,
Government Contractsf, Texas Instruments Incorporatedf, Semiconductor
Group (phone 972 480 7442).


*/

/* VQ Codebook file           */
/* (C) 1995 Texas Instruments */

#include	<stdio.h>
#include	"melp.h"

int fsvq_weighted = 0;

float fsvq_cb[2560] CCMRAM = {
0.822998f, 1.496297f, 0.584847f, 1.313507f, 0.846008f, 0.614041f, 0.615298f, 0.881819f, 1.227331f, 0.902116f, 
1.248150f, 1.020382f, 0.517184f, 1.489079f, 0.650498f, 0.716904f, 0.650349f, 1.260358f, 0.871024f, 0.907932f, 
1.167392f, 1.468091f, 0.743322f, 0.712255f, 1.564293f, 0.721041f, 0.528277f, 0.657527f, 0.763228f, 0.846655f, 
1.043080f, 1.570270f, 0.444422f, 0.933200f, 1.211773f, 0.669870f, 0.932675f, 0.806473f, 0.913787f, 0.868244f, 
0.759126f, 1.037894f, 1.126967f, 1.133186f, 0.789090f, 0.807399f, 1.054906f, 0.949898f, 1.007863f, 1.119437f, 
0.977225f, 1.130888f, 1.044601f, 1.432985f, 0.819888f, 0.517787f, 0.932401f, 0.964477f, 0.886867f, 0.895436f, 
0.666187f, 1.364039f, 1.088940f, 0.902131f, 1.110838f, 0.980791f, 0.926721f, 0.867719f, 0.925053f, 0.913544f, 
0.983185f, 1.460579f, 0.732273f, 0.923475f, 1.088579f, 0.952291f, 0.789664f, 1.025082f, 0.904670f, 0.854338f, 
0.697275f, 1.651033f, 0.506420f, 0.809603f, 1.113992f, 1.083678f, 0.629739f, 0.986236f, 0.871250f, 0.997090f, 
0.749416f, 1.354976f, 0.731452f, 1.281438f, 1.080946f, 1.037235f, 0.748186f, 0.821493f, 0.879839f, 0.965350f, 
0.976897f, 2.009469f, 0.741592f, 0.606862f, 0.644927f, 0.687413f, 0.760360f, 0.833318f, 0.869851f, 0.810534f, 
0.576891f, 1.527863f, 0.657703f, 1.006739f, 1.226803f, 0.786733f, 0.991212f, 0.821165f, 1.014984f, 0.878058f, 
0.517211f, 1.220859f, 0.886556f, 0.980153f, 0.884365f, 1.041315f, 0.949276f, 0.881296f, 1.373464f, 0.890748f, 
0.651809f, 1.106789f, 0.885180f, 1.329281f, 1.124388f, 0.626778f, 1.261132f, 0.822453f, 0.966925f, 0.806183f, 
0.614335f, 1.430380f, 0.899696f, 0.847168f, 0.624567f, 1.307056f, 1.360741f, 0.735438f, 0.854307f, 0.674763f, 
0.830604f, 1.373081f, 0.785967f, 0.735951f, 0.968745f, 1.100706f, 0.927619f, 0.728449f, 1.292031f, 0.884959f, 
1.084085f, 1.385767f, 0.448480f, 1.297458f, 0.770611f, 0.719263f, 1.080766f, 0.909836f, 0.838299f, 0.909742f, 
1.244608f, 1.158451f, 0.615757f, 1.169599f, 1.032735f, 0.921809f, 0.916509f, 1.060343f, 0.836990f, 0.767101f, 
1.313869f, 1.341417f, 0.481710f, 0.685601f, 1.086817f, 1.003461f, 0.762127f, 0.832518f, 1.081618f, 0.917168f, 
1.427137f, 0.932544f, 0.595881f, 0.652610f, 1.073852f, 0.847480f, 1.264058f, 0.899502f, 0.899264f, 0.958964f, 
1.027745f, 1.214124f, 0.896291f, 0.972030f, 0.841943f, 0.738307f, 1.048254f, 1.077882f, 0.952564f, 1.056319f, 
0.952252f, 1.098463f, 0.690316f, 1.175721f, 0.911712f, 0.962678f, 0.859269f, 1.138901f, 1.074558f, 0.924091f, 
0.902314f, 1.163750f, 1.143587f, 0.814860f, 0.923235f, 0.973077f, 1.098871f, 0.966014f, 0.968856f, 0.893133f, 
1.133879f, 1.110463f, 0.687589f, 0.793794f, 1.026535f, 1.076900f, 1.185281f, 0.821843f, 0.845464f, 1.079782f, 
0.623910f, 1.269921f, 0.722072f, 0.990256f, 1.183314f, 1.161476f, 0.677381f, 1.199311f, 0.902081f, 0.883634f, 
0.585861f, 1.189163f, 0.882952f, 1.134136f, 0.900218f, 1.263223f, 0.995922f, 1.011126f, 0.906268f, 0.863339f, 
0.687616f, 1.562003f, 0.815795f, 0.701934f, 0.789752f, 1.204232f, 0.821560f, 1.168157f, 0.888904f, 0.860778f, 
0.950686f, 1.329037f, 0.692678f, 0.754646f, 1.095995f, 1.446339f, 0.941535f, 0.710369f, 0.789949f, 0.826271f, 
0.520026f, 1.293024f, 0.938993f, 0.990412f, 0.897114f, 0.914170f, 1.358696f, 0.952011f, 0.936183f, 0.837973f, 
0.669622f, 1.291638f, 0.749196f, 1.167486f, 1.042641f, 0.721329f, 1.005261f, 1.252692f, 0.883186f, 0.854416f, 
0.497926f, 1.222508f, 1.403952f, 0.799058f, 0.798533f, 0.793545f, 1.264461f, 0.958949f, 0.843825f, 0.909886f, 
0.891705f, 1.342163f, 0.761635f, 0.758182f, 0.987397f, 1.008477f, 1.377249f, 0.845635f, 0.845744f, 0.822265f, 
1.174305f, 0.454482f, 0.432532f, 0.691549f, 1.066271f, 0.890505f, 0.845957f, 1.125649f, 1.338280f, 1.204068f, 
1.607432f, 0.688224f, 0.500617f, 1.288348f, 0.678978f, 0.674969f, 1.047764f, 1.012974f, 0.954688f, 0.803209f, 
1.739179f, 0.919542f, 0.639494f, 0.775935f, 1.021945f, 0.991820f, 0.887633f, 0.876449f, 0.796800f, 0.771028f, 
1.620174f, 1.211703f, 0.610139f, 1.372774f, 1.057336f, 0.618126f, 0.642995f, 0.667444f, 0.666172f, 0.676810f, 
1.219952f, 0.844191f, 1.016601f, 0.867402f, 1.006595f, 0.940309f, 0.893858f, 0.963053f, 0.730414f, 1.286290f, 
1.251753f, 1.004762f, 0.777132f, 1.203828f, 0.656382f, 0.657205f, 1.233246f, 0.874799f, 1.106710f, 0.855250f, 
1.348819f, 0.791939f, 1.030755f, 0.765314f, 1.014939f, 1.044297f, 0.747682f, 1.309667f, 0.853913f, 0.723126f, 
1.262759f, 1.109681f, 0.672002f, 1.109957f, 0.827608f, 1.272683f, 0.670943f, 1.068174f, 0.752511f, 0.878203f, 
1.108504f, 1.250712f, 0.620039f, 0.752463f, 1.439216f, 0.890828f, 1.018300f, 0.736766f, 0.910504f, 0.849118f, 
1.222589f, 1.083869f, 0.627894f, 1.150342f, 1.377353f, 0.785771f, 0.679900f, 0.897937f, 0.854521f, 0.920765f, 
1.326349f, 1.690290f, 1.188837f, 0.595281f, 0.602145f, 0.626852f, 0.676343f, 0.829212f, 0.785923f, 0.799661f, 
1.499772f, 1.400400f, 0.655881f, 0.892565f, 1.089036f, 0.702486f, 0.835749f, 0.800092f, 0.731263f, 0.835818f, 
1.126664f, 1.353291f, 0.898265f, 0.897870f, 0.934461f, 1.003119f, 0.982470f, 0.815886f, 0.952342f, 0.831774f, 
1.316478f, 1.060041f, 0.667653f, 1.065408f, 0.910377f, 1.002121f, 1.339044f, 0.710796f, 0.720291f, 0.813624f, 
0.976194f, 1.377380f, 1.071262f, 0.789567f, 1.085928f, 1.253806f, 1.017727f, 0.719049f, 0.561583f, 0.692329f, 
1.202869f, 1.059008f, 0.962883f, 0.999919f, 0.524897f, 1.074531f, 1.091141f, 0.910749f, 1.044517f, 0.859795f, 
1.413976f, 0.836644f, 0.666408f, 1.039645f, 1.088087f, 0.820217f, 0.816371f, 1.049252f, 1.083270f, 0.881172f, 
1.388093f, 0.807110f, 0.781561f, 0.964242f, 0.973557f, 1.138037f, 1.026733f, 0.970914f, 0.866461f, 0.841057f, 
1.456077f, 0.982162f, 0.557993f, 0.738683f, 1.375522f, 0.772422f, 0.644426f, 0.952329f, 0.954631f, 1.004692f, 
1.606208f, 1.220452f, 0.738208f, 0.744965f, 0.659231f, 0.813191f, 0.932141f, 0.922849f, 0.956161f, 0.892080f, 
1.126839f, 1.038057f, 0.935449f, 1.012686f, 1.080640f, 0.884338f, 1.126468f, 1.076987f, 0.817224f, 0.736383f, 
1.215351f, 0.845602f, 0.829299f, 1.204972f, 0.891515f, 0.934431f, 0.887728f, 0.938925f, 0.955741f, 1.114145f, 
1.206387f, 0.977863f, 1.051199f, 0.847855f, 0.939759f, 1.254109f, 0.970361f, 0.901040f, 0.844070f, 0.819544f, 
1.207602f, 0.976323f, 0.841307f, 0.870300f, 0.877422f, 0.988163f, 0.931714f, 1.031677f, 1.205409f, 0.903902f, 
1.095130f, 1.105129f, 0.722843f, 0.943180f, 1.211443f, 1.178861f, 0.634252f, 0.870933f, 1.011727f, 0.936443f, 
1.032014f, 0.998735f, 0.686262f, 1.100404f, 1.022352f, 1.222401f, 1.146689f, 0.812882f, 0.927129f, 0.801404f, 
1.131931f, 1.489739f, 0.677826f, 0.610733f, 0.759219f, 0.808122f, 1.042500f, 1.077132f, 1.035717f, 0.906736f, 
1.342504f, 1.076171f, 0.583400f, 0.764890f, 0.818097f, 1.293405f, 1.058200f, 0.852259f, 0.958646f, 0.872888f, 
1.308520f, 1.219689f, 0.935572f, 0.714861f, 1.129251f, 0.856944f, 0.920880f, 0.974834f, 0.821443f, 0.847930f, 
1.372592f, 0.887155f, 0.710732f, 1.029836f, 1.278897f, 0.650119f, 1.136552f, 0.881858f, 0.850047f, 0.819899f, 
1.019956f, 1.381944f, 1.089064f, 0.576825f, 0.594933f, 0.752016f, 1.265619f, 1.129530f, 0.867864f, 0.768122f, 
1.154864f, 1.069591f, 0.913967f, 0.796105f, 0.790255f, 0.854206f, 1.523905f, 0.856969f, 0.887946f, 0.756665f, 
0.874806f, 1.645517f, 0.834275f, 1.578196f, 0.903996f, 0.547038f, 0.565520f, 0.704114f, 0.697290f, 0.713786f, 
1.153418f, 1.095160f, 0.870564f, 1.655735f, 1.071838f, 0.806210f, 0.607539f, 0.566859f, 0.683404f, 0.826413f, 
0.830864f, 1.448871f, 1.014508f, 0.939034f, 1.574030f, 0.796490f, 0.654852f, 0.558685f, 0.641596f, 0.797132f, 
1.125819f, 1.396448f, 0.746324f, 1.295697f, 1.137447f, 1.301677f, 0.574765f, 0.486441f, 0.489204f, 0.608138f, 
0.832614f, 0.802739f, 1.148272f, 1.316531f, 1.305743f, 0.696667f, 0.940671f, 0.848198f, 0.872696f, 0.851311f, 
1.260278f, 0.958467f, 0.667246f, 1.406435f, 0.859092f, 0.534003f, 0.485425f, 0.723814f, 1.418320f, 0.944772f, 
0.887527f, 1.330678f, 1.062704f, 0.552689f, 1.098956f, 0.917567f, 0.874732f, 1.075172f, 0.845710f, 1.019528f, 
0.906302f, 1.326878f, 0.632127f, 0.781817f, 1.111568f, 0.753606f, 0.896250f, 0.945621f, 0.969063f, 1.304544f, 
0.163798f, 1.616260f, 0.520967f, 1.244674f, 0.597986f, 1.174228f, 0.802735f, 1.079115f, 0.892800f, 0.877604f, 
0.717419f, 1.075445f, 0.997204f, 1.206762f, 1.312107f, 1.316050f, 0.696587f, 0.745413f, 0.739740f, 0.731447f, 
0.339447f, 1.827655f, 0.684798f, 0.716559f, 0.676084f, 1.081139f, 0.894730f, 0.954454f, 0.948165f, 0.910477f, 
0.864667f, 1.451421f, 0.725543f, 1.176080f, 1.209637f, 1.083631f, 1.163663f, 0.662386f, 0.501862f, 0.463726f, 
0.563978f, 1.135516f, 0.835026f, 1.736364f, 1.000137f, 0.805360f, 0.828496f, 0.833563f, 0.776277f, 0.805186f, 
1.009051f, 1.360317f, 0.668259f, 1.417717f, 1.518623f, 0.638014f, 0.446922f, 0.496800f, 0.693633f, 0.726920f, 
0.186440f, 1.625134f, 0.835253f, 1.175778f, 0.860628f, 0.885086f, 1.011866f, 0.789303f, 1.010232f, 0.802450f, 
0.652311f, 1.599127f, 0.599516f, 1.058215f, 0.801753f, 0.992815f, 1.146092f, 0.829615f, 0.939228f, 0.837653f, 
0.759780f, 1.399480f, 0.987329f, 1.024824f, 0.974458f, 0.551246f, 1.150852f, 0.844956f, 1.016771f, 0.925568f, 
1.069814f, 1.160678f, 0.803250f, 1.193140f, 1.112463f, 0.744748f, 1.070724f, 0.739996f, 0.924675f, 0.942765f, 
1.168517f, 1.633441f, 0.774778f, 0.736824f, 1.089258f, 1.057042f, 0.783527f, 0.691403f, 0.779568f, 0.728487f, 
1.301817f, 1.572909f, 0.526128f, 0.558027f, 0.660410f, 1.078262f, 1.089774f, 0.718543f, 0.753433f, 0.965337f, 
0.891795f, 1.262297f, 0.911545f, 1.214103f, 0.776010f, 0.944986f, 1.138773f, 0.772798f, 0.957464f, 0.885334f, 
1.219015f, 1.048683f, 0.943178f, 1.150567f, 0.837824f, 0.566225f, 0.660764f, 1.219023f, 1.019092f, 0.988723f, 
0.925533f, 1.350162f, 1.164350f, 0.542695f, 1.227640f, 0.600203f, 1.205779f, 0.701896f, 0.932956f, 0.815466f, 
1.019130f, 1.292473f, 0.796847f, 0.819714f, 1.254208f, 0.522062f, 1.293349f, 0.823616f, 0.832862f, 0.890015f, 
0.686388f, 1.534513f, 1.023273f, 1.065238f, 0.769952f, 0.914897f, 0.958226f, 0.965983f, 0.847693f, 0.876086f, 
0.560425f, 1.321635f, 0.837563f, 1.105726f, 0.800833f, 0.952432f, 0.673960f, 1.327502f, 0.806885f, 1.135634f, 
0.722275f, 1.482196f, 1.269134f, 0.695424f, 0.734410f, 1.240968f, 0.873750f, 0.825209f, 0.794290f, 0.840055f, 
1.022015f, 1.408327f, 0.702067f, 0.966478f, 0.742264f, 1.204704f, 0.633885f, 0.888498f, 0.713166f, 1.231153f, 
0.512817f, 1.187577f, 0.939995f, 1.273059f, 1.261853f, 0.875396f, 0.884657f, 0.928591f, 0.900721f, 0.880112f, 
0.781537f, 1.223652f, 0.854824f, 0.972599f, 1.347144f, 0.807227f, 0.911694f, 0.956919f, 0.990262f, 0.893345f, 
0.358832f, 1.601542f, 1.125781f, 0.730841f, 0.795475f, 0.856229f, 1.070817f, 0.869601f, 1.043598f, 0.896567f, 
0.821456f, 1.676333f, 0.931807f, 0.740210f, 0.946762f, 0.917425f, 0.936539f, 0.884692f, 0.872158f, 0.827619f, 
1.133434f, 1.069057f, 0.628708f, 1.348112f, 1.024242f, 0.726333f, 0.485013f, 0.517711f, 0.812878f, 1.483409f, 
1.439495f, 0.401963f, 0.704352f, 1.185582f, 1.196889f, 0.894400f, 0.762308f, 0.871978f, 1.004571f, 0.965074f, 
1.355857f, 1.217795f, 0.623188f, 0.626000f, 1.080819f, 1.443039f, 0.690217f, 0.676470f, 0.752167f, 0.890824f, 
1.384203f, 0.893545f, 0.571820f, 1.422045f, 1.054457f, 0.896980f, 0.929532f, 0.779836f, 0.816629f, 0.774798f, 
1.272930f, 0.807536f, 0.943865f, 1.161822f, 1.109685f, 0.883353f, 0.756987f, 1.183318f, 0.792499f, 0.818768f, 
1.368426f, 0.939970f, 0.927314f, 1.372501f, 0.966845f, 0.661820f, 0.817570f, 0.813094f, 0.874638f, 0.905751f, 
1.234512f, 0.812394f, 1.092298f, 0.956999f, 0.926831f, 1.159350f, 0.560790f, 0.914404f, 1.104409f, 0.951357f, 
1.462063f, 1.107453f, 0.736919f, 1.182041f, 0.753060f, 0.817381f, 0.845724f, 0.960321f, 0.930034f, 0.870101f, 
1.154263f, 1.149050f, 0.969239f, 1.003195f, 0.709246f, 1.334899f, 0.539388f, 0.648414f, 1.170228f, 0.841587f, 
1.363427f, 0.856319f, 0.848329f, 1.330223f, 1.580245f, 0.593904f, 0.534564f, 0.577523f, 0.647285f, 0.799871f, 
1.430748f, 1.277622f, 0.535910f, 1.316419f, 0.704018f, 1.139968f, 0.844730f, 0.708186f, 0.689915f, 0.673166f, 
1.456831f, 0.852769f, 0.836842f, 1.661979f, 0.555156f, 0.659789f, 0.754965f, 0.765223f, 0.801905f, 0.871901f, 
1.219340f, 0.941999f, 1.021315f, 1.258016f, 0.869648f, 1.086416f, 1.006363f, 0.806097f, 0.807889f, 0.739562f, 
1.269435f, 1.217910f, 1.091920f, 1.130622f, 1.241678f, 0.548636f, 0.659441f, 0.769661f, 0.738142f, 0.844145f, 
1.109102f, 1.109600f, 0.921873f, 1.080103f, 0.644065f, 1.551581f, 0.917328f, 0.782032f, 0.649409f, 0.682361f, 
1.148823f, 1.115256f, 0.784950f, 1.519787f, 0.632186f, 0.880947f, 0.965093f, 0.738516f, 0.923041f, 0.843738f, 
1.099162f, 1.072237f, 1.059239f, 1.012868f, 1.091543f, 0.820111f, 0.632757f, 0.796845f, 1.140959f, 1.032531f, 
1.382078f, 1.014650f, 0.855020f, 1.088445f, 1.147617f, 1.054602f, 0.759230f, 0.758359f, 0.828497f, 0.830315f, 
1.331108f, 0.911897f, 0.551680f, 0.739304f, 1.080511f, 1.173246f, 0.671436f, 0.925538f, 1.082333f, 1.110124f, 
1.380841f, 1.130295f, 0.743747f, 0.910074f, 0.957719f, 0.986217f, 0.885270f, 0.809240f, 0.914088f, 1.051811f, 
1.310270f, 0.998818f, 0.989857f, 1.025202f, 0.906801f, 0.876459f, 0.895856f, 0.981348f, 0.982188f, 0.901957f, 
1.442392f, 0.947518f, 1.052543f, 0.888925f, 1.092888f, 0.674498f, 0.920650f, 0.987177f, 0.890263f, 0.816537f, 
1.173251f, 0.879037f, 1.128982f, 0.905439f, 1.302826f, 1.072854f, 0.709855f, 0.689286f, 1.000834f, 0.819403f, 
1.162547f, 0.939193f, 1.038151f, 0.930689f, 0.914292f, 0.877584f, 1.144403f, 0.667857f, 1.257437f, 0.810249f, 
0.957634f, 1.145630f, 1.008914f, 1.045813f, 1.030746f, 1.071616f, 0.801657f, 0.909400f, 0.880216f, 1.014015f, 
1.250553f, 1.148173f, 0.606277f, 0.991795f, 0.997859f, 0.688890f, 0.942568f, 0.922857f, 1.233180f, 0.891771f, 
1.223899f, 1.343365f, 0.813470f, 0.600631f, 0.514261f, 1.292102f, 0.994158f, 1.012705f, 0.774822f, 0.889761f, 
1.434258f, 1.190874f, 0.478282f, 0.454840f, 0.731792f, 1.170314f, 0.776934f, 1.201793f, 0.865726f, 0.993823f, 
1.075483f, 0.950940f, 1.056806f, 0.939311f, 0.767863f, 1.050672f, 0.923138f, 1.208091f, 0.957328f, 0.914622f, 
1.152850f, 0.985329f, 0.758860f, 0.902903f, 1.268339f, 0.822622f, 0.951593f, 0.972154f, 0.988798f, 1.010038f, 
0.934316f, 1.213602f, 1.137776f, 0.530840f, 0.583216f, 1.327735f, 0.648220f, 1.122533f, 0.983140f, 0.947688f, 
1.096461f, 1.329950f, 1.056696f, 1.096312f, 0.518753f, 0.667957f, 1.377914f, 0.802439f, 0.713627f, 0.728387f, 
0.438479f, 0.986558f, 0.795180f, 1.048475f, 1.212747f, 1.336801f, 0.859633f, 1.040980f, 0.943136f, 0.921149f, 
1.106514f, 0.482598f, 0.612108f, 1.642264f, 0.798236f, 0.780622f, 0.825869f, 0.883680f, 1.122055f, 0.975218f, 
0.977340f, 0.929082f, 0.748423f, 0.688517f, 1.866792f, 0.978102f, 0.704420f, 0.691328f, 0.814419f, 0.732273f, 
2.061007f, 1.317233f, 0.531080f, 0.663650f, 0.466228f, 0.673965f, 0.663756f, 0.680624f, 0.722060f, 0.735546f, 
0.324483f, 0.566419f, 1.626532f, 0.909957f, 0.767043f, 1.218518f, 0.923857f, 0.781191f, 1.034489f, 0.929690f, 
1.132776f, 0.664024f, 0.658276f, 1.115888f, 1.058611f, 0.773592f, 1.143017f, 1.345343f, 0.885859f, 0.793138f, 
0.693193f, 0.957946f, 1.074530f, 0.991271f, 1.178869f, 1.050262f, 1.231718f, 0.919607f, 0.838514f, 0.820971f, 
0.981206f, 1.282808f, 0.628439f, 0.831905f, 0.871888f, 1.000360f, 1.072068f, 1.359583f, 0.865264f, 0.714229f, 
0.444708f, 1.320901f, 0.863009f, 0.823633f, 1.282252f, 1.175766f, 1.016159f, 0.800445f, 0.885734f, 0.918392f, 
0.524278f, 0.903183f, 0.842282f, 0.999358f, 1.663203f, 0.862494f, 0.990065f, 0.863742f, 0.861246f, 0.885159f, 
0.647517f, 1.630489f, 0.674425f, 0.552789f, 1.367019f, 0.802523f, 1.078554f, 0.810538f, 0.843750f, 0.824923f, 
1.157635f, 1.168651f, 0.661005f, 0.556302f, 1.240422f, 0.970912f, 0.829631f, 1.237884f, 0.917322f, 0.831318f, 
0.271398f, 0.978008f, 0.699287f, 1.501347f, 0.903792f, 1.105029f, 0.960131f, 1.036695f, 1.001109f, 0.890359f, 
0.275143f, 0.628587f, 1.143603f, 1.112293f, 1.315251f, 1.071179f, 0.889841f, 0.954181f, 1.018312f, 0.964080f, 
0.659209f, 1.447333f, 0.894087f, 1.001992f, 0.839399f, 1.449942f, 0.796803f, 0.843993f, 0.756016f, 0.817636f, 
0.853138f, 1.064738f, 0.855133f, 0.742170f, 0.868512f, 1.370756f, 0.989681f, 1.038327f, 0.937196f, 0.993200f, 
0.973539f, 1.188932f, 1.023116f, 0.931037f, 1.059522f, 0.699512f, 0.709015f, 1.360161f, 0.889684f, 0.811761f, 
1.226588f, 1.022695f, 0.719215f, 1.364611f, 0.676914f, 0.710196f, 1.255418f, 1.207082f, 0.643748f, 0.569250f, 
0.911359f, 1.344114f, 1.042414f, 0.518823f, 1.545711f, 0.394875f, 0.583463f, 1.042424f, 0.973970f, 0.781663f, 
1.728382f, 0.630457f, 0.384633f, 0.410263f, 0.623340f, 0.756137f, 0.963416f, 1.240436f, 1.179740f, 0.957703f, 
0.738959f, 0.590931f, 1.110580f, 1.101743f, 0.983178f, 0.969963f, 1.084357f, 1.136055f, 1.021410f, 0.944931f, 
1.244427f, 0.569958f, 1.057313f, 1.369461f, 0.723367f, 0.805159f, 1.027868f, 1.091877f, 0.873967f, 0.776658f, 
0.787743f, 0.905228f, 1.203273f, 0.843008f, 1.182612f, 1.029414f, 0.763719f, 1.097128f, 0.900016f, 1.016990f, 
1.314427f, 1.012982f, 0.695385f, 0.878737f, 0.749022f, 0.792771f, 1.048592f, 1.421864f, 0.816344f, 0.837093f, 
0.284264f, 1.037450f, 0.783668f, 1.045137f, 1.085681f, 0.925955f, 1.010468f, 0.963587f, 1.285465f, 1.083612f, 
0.182413f, 0.501944f, 0.613194f, 0.864945f, 1.046530f, 1.201125f, 1.222115f, 1.201816f, 1.144754f, 1.100226f, 
0.399720f, 1.302627f, 1.339572f, 0.544091f, 1.113712f, 0.704227f, 0.959569f, 1.086265f, 0.919326f, 0.996120f, 
1.312087f, 1.234779f, 1.155127f, 0.573204f, 0.603170f, 1.675500f, 0.578462f, 0.549438f, 0.586763f, 0.627105f, 
0.347498f, 1.019206f, 0.902255f, 0.918363f, 1.078096f, 0.895444f, 1.295650f, 1.236476f, 0.896594f, 0.955950f, 
0.228297f, 0.547356f, 1.316811f, 1.334579f, 0.850478f, 0.739122f, 1.162684f, 1.153175f, 0.961239f, 0.847730f, 
0.450951f, 1.164991f, 1.356497f, 0.748838f, 1.098313f, 1.180630f, 0.960353f, 0.882357f, 0.871493f, 0.801907f, 
1.101005f, 1.177952f, 1.577841f, 0.463778f, 0.535020f, 0.573959f, 0.857461f, 1.214102f, 0.824723f, 0.827632f, 
1.008192f, 0.512187f, 0.511630f, 0.803656f, 1.363784f, 1.397129f, 1.041883f, 0.945399f, 0.880500f, 0.836761f, 
1.333032f, 0.522169f, 0.512363f, 0.626419f, 0.780427f, 0.951713f, 1.495366f, 1.235918f, 0.888195f, 0.836141f, 
1.680621f, 0.528954f, 0.445504f, 0.623836f, 1.316133f, 1.053039f, 0.890863f, 0.877480f, 0.775161f, 0.883213f, 
2.235511f, 0.589895f, 0.429925f, 0.577054f, 0.680209f, 0.667395f, 0.784315f, 0.803936f, 0.861809f, 0.801209f, 
1.092796f, 0.555938f, 1.481165f, 0.731586f, 1.165349f, 0.972450f, 0.847847f, 0.832928f, 0.893096f, 0.925555f, 
1.276456f, 0.719658f, 0.981702f, 1.037082f, 1.176864f, 0.684247f, 0.782879f, 0.891723f, 1.117659f, 1.034450f, 
1.228245f, 0.771626f, 1.121788f, 0.749934f, 0.884593f, 0.958108f, 1.233677f, 1.045060f, 0.933820f, 0.833295f, 
1.469187f, 0.712424f, 0.977325f, 0.707326f, 1.237597f, 0.953937f, 0.835168f, 0.794138f, 0.991406f, 0.934207f, 
1.079164f, 1.065143f, 1.263724f, 0.575489f, 1.628970f, 0.516204f, 0.546497f, 0.527023f, 0.774807f, 1.079119f, 
1.337945f, 0.994695f, 0.675169f, 0.865744f, 1.373516f, 1.324911f, 0.866779f, 0.633895f, 0.599425f, 0.727921f, 
1.511212f, 0.641169f, 1.710560f, 0.731522f, 0.590315f, 0.546117f, 0.624898f, 0.778970f, 0.908906f, 0.903649f, 
1.760845f, 1.236091f, 1.067203f, 0.487204f, 0.655720f, 0.713362f, 0.697764f, 0.749475f, 0.847174f, 0.921298f, 
1.242002f, 1.065400f, 0.986706f, 0.626575f, 1.306310f, 0.681929f, 0.717473f, 0.615010f, 1.350818f, 0.832838f, 
1.114715f, 0.651334f, 1.082160f, 1.095767f, 1.064034f, 1.122643f, 1.004475f, 0.903535f, 0.874168f, 0.865362f, 
1.244497f, 1.005714f, 1.193496f, 0.734583f, 0.598761f, 1.274922f, 1.289539f, 0.614727f, 0.688696f, 0.778442f, 
1.408250f, 0.839767f, 1.067828f, 0.572007f, 0.672582f, 1.239141f, 0.865001f, 0.858314f, 1.080318f, 0.941161f, 
1.250488f, 0.918235f, 1.101326f, 0.668242f, 1.365644f, 0.555295f, 0.552784f, 1.259466f, 0.907460f, 0.811412f, 
1.631045f, 0.643427f, 0.448596f, 0.462433f, 0.721966f, 1.376064f, 1.149863f, 0.918544f, 0.813496f, 0.874574f, 
1.535075f, 1.109493f, 1.002904f, 0.867410f, 1.515072f, 0.754291f, 0.569348f, 0.512821f, 0.594932f, 0.664862f, 
1.968050f, 0.717136f, 1.151858f, 0.741070f, 0.764881f, 0.686026f, 0.715694f, 0.699206f, 0.765000f, 0.778737f, 
1.413788f, 0.795490f, 1.377022f, 0.733397f, 1.230761f, 0.728025f, 0.815985f, 0.866154f, 0.713555f, 0.821627f, 
1.339077f, 0.710095f, 1.014431f, 1.092420f, 0.988468f, 0.688934f, 1.213969f, 0.865531f, 0.928889f, 0.852068f, 
1.172569f, 0.971105f, 1.147345f, 0.503528f, 1.077878f, 1.006880f, 0.936191f, 1.024685f, 0.978125f, 0.897520f, 
1.346133f, 0.825702f, 1.278602f, 0.712776f, 0.990801f, 0.824307f, 0.741063f, 0.777009f, 1.172757f, 0.958583f, 
0.838360f, 1.061588f, 1.184451f, 0.806865f, 1.445930f, 0.716610f, 1.122729f, 0.763437f, 0.824729f, 0.830950f, 
1.276108f, 0.881797f, 1.013445f, 0.821855f, 1.264900f, 1.025945f, 1.227647f, 0.703569f, 0.659312f, 0.734361f, 
1.043635f, 1.011762f, 1.513310f, 0.739962f, 0.660585f, 0.587323f, 0.680578f, 0.841721f, 1.167268f, 1.132996f, 
1.473979f, 0.627258f, 1.381177f, 0.659284f, 0.759202f, 1.049849f, 1.020305f, 0.870139f, 0.779335f, 0.834162f, 
1.308547f, 0.926336f, 1.119570f, 0.550398f, 1.232051f, 0.605843f, 1.181402f, 0.819554f, 0.865953f, 0.920083f, 
1.337645f, 0.769449f, 1.229177f, 0.813618f, 0.735630f, 0.883470f, 1.569295f, 0.634285f, 0.606052f, 0.688148f, 
1.290794f, 1.093894f, 1.145434f, 0.552063f, 0.804350f, 0.769436f, 0.840595f, 1.089482f, 1.009731f, 1.051359f, 
1.364932f, 0.913519f, 1.316632f, 0.718362f, 0.529225f, 0.723872f, 1.181281f, 0.876150f, 0.962565f, 0.918262f, 
0.803741f, 1.388152f, 0.980932f, 1.386743f, 0.402886f, 1.229764f, 0.855613f, 0.743859f, 0.738745f, 0.812385f, 
1.187083f, 1.328233f, 0.750736f, 1.808456f, 0.498683f, 0.428506f, 0.498878f, 0.815022f, 0.756569f, 0.712230f, 
1.008780f, 1.634667f, 0.998899f, 1.114864f, 1.106568f, 0.814867f, 0.677242f, 0.626767f, 0.727848f, 0.701162f, 
1.442123f, 1.578969f, 1.235055f, 1.279799f, 0.604508f, 0.459123f, 0.486663f, 0.548079f, 0.537477f, 0.639041f, 
0.824699f, 0.832512f, 1.286809f, 0.946005f, 0.788899f, 1.581450f, 0.819352f, 0.804348f, 0.757910f, 0.797158f, 
1.173084f, 0.852089f, 0.837159f, 1.215371f, 0.614107f, 0.664921f, 0.798941f, 1.185092f, 1.404650f, 0.752108f, 
0.837980f, 1.195548f, 1.251800f, 1.166862f, 1.139151f, 0.630036f, 0.966812f, 0.823920f, 0.819578f, 0.833867f, 
1.284059f, 1.360185f, 0.903226f, 1.260066f, 0.869280f, 0.794052f, 0.767674f, 0.784999f, 0.770146f, 0.814413f, 
0.434909f, 1.062061f, 0.820721f, 0.980006f, 0.915903f, 1.352711f, 1.363232f, 0.818512f, 0.933755f, 0.804752f, 
0.140705f, 0.369673f, 0.761460f, 1.721146f, 1.281940f, 0.814390f, 0.770430f, 0.912685f, 1.029093f, 0.894100f, 
0.381833f, 1.386068f, 0.895360f, 0.756433f, 0.795777f, 0.665474f, 1.098763f, 1.438104f, 1.037485f, 0.828884f, 
0.848084f, 1.088554f, 0.824684f, 0.776900f, 0.721938f, 0.676660f, 0.800316f, 1.135752f, 1.511374f, 1.057070f, 
0.675218f, 1.083363f, 1.015844f, 1.396638f, 0.903676f, 0.983177f, 0.888414f, 1.062584f, 0.890620f, 0.821218f, 
0.754970f, 0.952752f, 1.127383f, 1.539338f, 0.700672f, 0.751028f, 0.640102f, 0.797817f, 1.188132f, 0.971816f, 
0.701999f, 1.321737f, 1.118923f, 1.317673f, 0.798997f, 1.146361f, 0.653062f, 0.923909f, 0.716226f, 0.881342f, 
0.916108f, 1.387334f, 0.769658f, 1.200061f, 0.617306f, 1.096865f, 0.828575f, 1.077143f, 0.950269f, 0.767253f, 
0.662335f, 1.292372f, 1.294051f, 1.134329f, 0.611097f, 0.878492f, 0.979876f, 0.932184f, 0.972586f, 0.870668f, 
1.081800f, 1.056505f, 1.431825f, 1.568379f, 0.608668f, 0.601313f, 0.533137f, 0.646402f, 0.768233f, 0.839110f, 
1.062379f, 1.439992f, 1.195124f, 1.101291f, 0.690349f, 0.686199f, 0.744970f, 0.782839f, 0.947571f, 0.913290f, 
1.302173f, 1.079498f, 1.059178f, 0.961715f, 0.721412f, 0.548559f, 0.490001f, 0.649919f, 1.527619f, 0.917298f, 
0.680923f, 1.193324f, 1.324460f, 1.076160f, 0.940757f, 1.158478f, 1.016504f, 0.799201f, 0.766968f, 0.708056f, 
1.013158f, 0.953016f, 1.286560f, 1.218908f, 0.634730f, 1.131540f, 0.788277f, 0.928104f, 0.871793f, 0.842399f, 
0.801060f, 0.948640f, 1.501946f, 0.737009f, 0.751623f, 1.024697f, 1.091762f, 0.879438f, 0.970670f, 0.874395f, 
1.322228f, 1.272781f, 1.083638f, 0.879445f, 0.649796f, 0.924154f, 0.851784f, 0.949572f, 0.890756f, 0.876190f, 
0.308295f, 1.165975f, 1.273902f, 1.153456f, 0.938787f, 0.761951f, 0.988352f, 0.937937f, 0.984994f, 0.988803f, 
0.307028f, 0.833986f, 1.891761f, 1.166166f, 0.526468f, 0.545358f, 0.772629f, 0.838092f, 0.849941f, 1.006412f, 
0.724400f, 1.661022f, 1.407543f, 0.659395f, 0.621709f, 0.664584f, 0.781703f, 0.915312f, 0.912252f, 0.868291f, 
0.899730f, 0.520003f, 2.050203f, 0.570193f, 0.525624f, 0.618870f, 0.773975f, 0.953262f, 0.860057f, 0.852288f, 
0.564036f, 1.194072f, 1.054038f, 1.309234f, 0.682175f, 1.184083f, 1.261020f, 0.720925f, 0.837966f, 0.682236f, 
0.705321f, 0.906931f, 1.440192f, 1.246568f, 0.945792f, 0.911725f, 0.914322f, 0.903469f, 0.819844f, 0.853160f, 
0.639259f, 1.118893f, 1.183435f, 0.912825f, 0.722814f, 1.107206f, 0.903505f, 1.289695f, 0.937470f, 0.852877f, 
0.833210f, 1.220093f, 1.668781f, 0.922503f, 0.998916f, 0.696036f, 0.765626f, 0.779931f, 0.724635f, 0.754248f, 
1.214346f, 0.962383f, 1.132890f, 0.827035f, 0.876470f, 1.255731f, 0.611676f, 0.550693f, 0.663031f, 1.355367f, 
1.790710f, 0.452581f, 0.576174f, 0.955171f, 0.930091f, 0.858695f, 1.025674f, 0.874218f, 0.875633f, 0.842868f, 
1.436801f, 0.888196f, 1.189311f, 0.679367f, 1.104152f, 1.351368f, 0.585875f, 0.677641f, 0.703740f, 0.775152f, 
1.614636f, 0.783579f, 0.883180f, 1.156453f, 0.973477f, 0.848164f, 0.830311f, 0.892666f, 0.763745f, 0.831350f, 
1.372060f, 0.499597f, 1.000811f, 0.900767f, 0.931695f, 0.898965f, 1.028259f, 1.067040f, 0.960141f, 0.995706f, 
1.464549f, 0.744441f, 0.906385f, 0.936059f, 0.731646f, 0.716360f, 0.829522f, 1.117880f, 1.156979f, 1.018394f, 
1.367898f, 0.866499f, 1.263666f, 1.112268f, 1.167850f, 0.937974f, 0.788936f, 0.718079f, 0.635187f, 0.707080f, 
1.439445f, 0.795863f, 0.796972f, 1.211896f, 0.538767f, 1.255454f, 0.958684f, 0.857981f, 0.848545f, 0.824913f, 
1.376381f, 0.568678f, 0.926291f, 0.641770f, 0.834535f, 1.808678f, 0.804428f, 0.607970f, 0.669675f, 0.720965f, 
1.355563f, 0.460449f, 0.596175f, 1.214770f, 0.946022f, 1.352957f, 0.860313f, 0.864696f, 0.785836f, 0.918103f, 
1.435024f, 0.909544f, 1.041289f, 1.123733f, 0.794294f, 1.439099f, 0.648301f, 0.574374f, 0.602775f, 0.780902f, 
1.516270f, 0.918985f, 0.927275f, 1.189389f, 0.590144f, 0.748748f, 1.248918f, 0.683386f, 0.755543f, 0.882486f, 
1.476744f, 0.514611f, 1.218581f, 1.065365f, 0.862836f, 0.922786f, 0.764142f, 0.839729f, 0.935193f, 0.933221f, 
1.315547f, 0.722841f, 1.311024f, 1.315785f, 0.913893f, 0.706439f, 0.682783f, 0.788285f, 0.877441f, 0.888931f, 
1.348712f, 0.858988f, 1.055635f, 1.052220f, 0.611431f, 1.171928f, 0.730139f, 1.115700f, 0.744873f, 0.946277f, 
1.180305f, 1.053248f, 0.878721f, 1.288189f, 0.507336f, 1.103290f, 0.705925f, 1.007651f, 0.841461f, 1.044969f, 
1.196638f, 1.080029f, 1.301461f, 0.997280f, 0.885975f, 0.846955f, 0.887870f, 0.844710f, 0.873575f, 0.870310f, 
1.373492f, 1.068929f, 1.077698f, 1.096515f, 0.998252f, 0.717247f, 1.234505f, 0.694028f, 0.663647f, 0.627234f, 
1.437332f, 1.207382f, 1.145016f, 0.902884f, 0.999814f, 1.049959f, 0.751617f, 0.679969f, 0.707880f, 0.681629f, 
1.540923f, 0.966825f, 1.074880f, 0.967647f, 0.780575f, 0.824665f, 0.721806f, 0.771586f, 0.917974f, 1.059911f, 
1.075058f, 0.874560f, 1.223286f, 0.875247f, 1.114946f, 0.785841f, 1.030228f, 1.006401f, 0.939058f, 0.894774f, 
1.230599f, 0.763269f, 1.223421f, 1.021346f, 0.751078f, 0.863709f, 0.928759f, 0.989248f, 1.037576f, 0.975537f, 
1.200394f, 0.826452f, 1.374917f, 0.728714f, 0.749645f, 1.169742f, 0.809933f, 1.098679f, 0.840553f, 0.806698f, 
1.458186f, 0.835033f, 1.120633f, 0.933190f, 0.831612f, 1.053974f, 1.060913f, 0.785122f, 0.845646f, 0.769115f, 
1.087334f, 1.237373f, 1.295267f, 0.657919f, 1.094758f, 1.035074f, 0.693941f, 0.869327f, 0.868297f, 0.787626f, 
1.183917f, 0.792976f, 1.143049f, 0.749982f, 0.626687f, 0.658678f, 0.983599f, 1.416025f, 1.044253f, 0.931234f, 
1.694116f, 1.108393f, 1.504700f, 0.828677f, 0.586589f, 0.658925f, 0.648047f, 0.676080f, 0.628926f, 0.681370f, 
1.363659f, 0.859205f, 1.134321f, 1.227826f, 0.519545f, 0.570781f, 0.847817f, 1.035284f, 0.967904f, 0.993060f, 
1.202407f, 0.995001f, 1.034142f, 0.944991f, 0.778536f, 0.657893f, 1.164819f, 0.964661f, 0.913810f, 1.114029f, 
1.325400f, 0.953743f, 1.087893f, 1.003095f, 0.754906f, 0.862034f, 1.119859f, 1.201467f, 0.736865f, 0.616466f, 
1.321790f, 0.767809f, 1.313064f, 0.954328f, 0.816200f, 0.607967f, 0.663671f, 1.355803f, 0.816644f, 0.850276f, 
1.493994f, 1.117090f, 1.211209f, 1.311853f, 0.619853f, 0.708056f, 0.764515f, 0.708914f, 0.718302f, 0.743372f};
