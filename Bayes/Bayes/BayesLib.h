#pragma once

#ifdef BAYESLIB_EXPORTS
#define BAYESLIB_API __declspec(dllexport)
#else
#define BAYESLIB_API __declspec(dllimport)
#endif

extern "C" BAYESLIB_API double BAYES(double Pa, double Pb, double PbIFa);