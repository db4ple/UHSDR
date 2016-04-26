/*  -*-  mode: c; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4; coding: utf-8  -*-  */
/************************************************************************************
**                                                                                 **
**                               mcHF QRP Transceiver                              **
**                             K Atanassov - M0NKA 2014                            **
**                                                                                 **
**---------------------------------------------------------------------------------**
**                                                                                 **
**  File name:                                                                     **
**  Description:                                                                   **
**  Last Modified:                                                                 **
**  Licence:		CC BY-NC-SA 3.0                                                **
************************************************************************************/

#include "filters.h"
//
// Filter designed 20141202 by C. Turner, KA7OEI using MatLAB fdatools
//
// NOTE:
//	- IIR structure is Lattice Autoregressive Moving-Average (ARMA)
//	- ARM FIR/IIR algorithms require time reverse-order coefficients!!!
//
//	Nominal 750 Hz center-frequency Filter:
//
// *** 12 KSPS Sample Rate!
//
//	10th order Least p-th Norm. bandpass filter
//	Fstop:  320, 1185 Hz
//	Fpass:  525, 975 Hz
//	-6dB points:  500, 998  480, 1034 Hz
//	-20dB points: 454, 1041    410, 1084 Hz
//	-40dB points: 370, 1125     <304, 1184 Hz
//	-55dB point:  <320Hz  -60 dB:  >1283 Hz
//
#define IIR_500hz_numStages 10
const arm_iir_lattice_instance_f32 IIR_500hz_750 =
{
    .numStages = IIR_500hz_numStages,
    .pkCoeffs  = (float*) (const float[])
    {
        0.7450181244202,
        -0.9084574667981,
        0.9790083293996,
        -0.9303082589799,
        0.9883388157099,
        -0.9268194870575,
        0.9907447739419,
        -0.919714678964,
        0.9893355692757,
        -0.9435646976164
    },

    .pvCoeffs = (float*) (const float[])
    {
        -1.61639285742e-07,
        -2.532569769139e-06,
        -1.730815165529e-05,
        -6.199614625535e-05,
        -0.0001162330723378,
        -9.354099226825e-05,
        9.396401192372e-06,
        2.784282263339e-06,
        8.547158547822e-06,
        5.265868366272e-07,
        -7.389379416329e-07
    }
};
//
// 850 Hz center
//
const arm_iir_lattice_instance_f32 IIR_500hz_850 =
{
    .numStages = IIR_500hz_numStages,
    .pkCoeffs  = (float*) (const float[])
    {
        0.7401338925506,
        -0.8867593927342,
        0.9778465129623,
        -0.9094003580498,
        0.9883168161429,
        -0.9055217486004,
        0.9903863113441,
        -0.8954747103238,
        0.9912950685125,
        -0.9298872553011
    },

    .pvCoeffs = (float*) (const float[])
    {
        -4.410143019036e-06,
        -9.236919139671e-05,
        -0.0003954308979742,
        -0.0003955563639255,
        -0.0001628454905818,
        0.0001098763251995,
        6.339131935123e-05,
        2.488401959762e-05,
        -7.761948232174e-06,
        -3.463637105875e-06,
        3.023849497139e-07
    }
};
//
// 950 Hz center
//
const arm_iir_lattice_instance_f32 IIR_500hz_950 =
{
    .numStages = IIR_500hz_numStages,
    .pkCoeffs  = (float*) (const float[])
    {
        0.7561294931445,
        -0.8664471899292,
        0.9790444302334,
        -0.8864086051206,
        0.9889574393432,
        -0.8826528972432,
        0.9908739731213,
        -0.8721677687198,
        0.9905929406153,
        -0.9077406187546
    },

    .pvCoeffs = (float*) (const float[])
    {
        -1.978764105412e-06,
        -4.109388008507e-05,
        -0.0002182934662175,
        -0.0002429079035953,
        -0.0002277987829458,
        0.0001122347644774,
        6.888195567177e-05,
        2.855449207125e-05,
        -6.041821715252e-06,
        -4.915517444392e-06,
        3.936206528372e-07
    }
};
//
// 650 Hz center
//
const arm_iir_lattice_instance_f32 IIR_500hz_650 =
{
    .numStages = IIR_500hz_numStages,
    .pkCoeffs  = (float*) (const float[])
    {
        0.7629545983553,
        -0.9292246993992,
        0.9812440354719,
        -0.9481158800736,
        0.9886964977718,
        -0.9455424450397,
        0.9898872346552,
        -0.9387191189796,
        0.9935074333889,
        -0.9667663712751
    },

    .pvCoeffs = (float*) (const float[])
    {
        7.913288912416e-08,
        -8.145261857675e-06,
        9.724845240669e-05,
        0.0002513968527392,
        0.0001566426842087,
        -1.692018078797e-05,
        -2.026140586575e-05,
        -1.410159029616e-05,
        -3.517554836743e-07,
        9.445267691075e-07,
        6.313896488397e-08
    }
};
//
// 550 Hz center
//
const arm_iir_lattice_instance_f32 IIR_500hz_550 =
{
    .numStages = IIR_500hz_numStages,
    .pkCoeffs  = (float*) (const float[])
    {
        0.7444824297014,
        -0.9426910512095,
        0.9809095416549,
        -0.9635826118077,
        0.9879143935335,
        -0.9619675085485,
        0.9892963956729,
        -0.9551745584075,
        0.9937943260814,
        -0.980312269594
    },

    .pvCoeffs = (float*) (const float[])
    {
        6.54693860799e-11,
        -1.725286655686e-08,
        1.274335799922e-06,
        -2.347197649254e-05,
        0.0001149607579105,
        -5.20632558042e-05,
        -1.133152510209e-06,
        -9.492268935446e-06,
        3.245552848263e-08,
        5.879262051272e-07,
        -1.546228266662e-08
    }
};
