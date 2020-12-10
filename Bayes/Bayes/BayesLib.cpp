// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "BayesLib.h"

double BAYES(double Pa, double Pb, double PbIFa)
{
    return PbIFa * Pa / Pb;
}