// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/rankUncertainty.h"
#include <Rcpp.h>
#include <string>
#include <set>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// countPrincipalDownSets
Rcpp::IntegerVector countPrincipalDownSets(Rcpp::NumericVector left, Rcpp::NumericVector right);
static SEXP _rankUncertainty_countPrincipalDownSets_try(SEXP leftSEXP, SEXP rightSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type left(leftSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type right(rightSEXP);
    rcpp_result_gen = Rcpp::wrap(countPrincipalDownSets(left, right));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _rankUncertainty_countPrincipalDownSets(SEXP leftSEXP, SEXP rightSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_rankUncertainty_countPrincipalDownSets_try(leftSEXP, rightSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// getCompatibility
bool getCompatibility(Rcpp::IntegerVector ranking, Rcpp::NumericVector left, Rcpp::NumericVector right);
static SEXP _rankUncertainty_getCompatibility_try(SEXP rankingSEXP, SEXP leftSEXP, SEXP rightSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type ranking(rankingSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type left(leftSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type right(rightSEXP);
    rcpp_result_gen = Rcpp::wrap(getCompatibility(ranking, left, right));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _rankUncertainty_getCompatibility(SEXP rankingSEXP, SEXP leftSEXP, SEXP rightSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_rankUncertainty_getCompatibility_try(rankingSEXP, leftSEXP, rightSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// getIndexIntervals
Rcpp::DataFrame getIndexIntervals(Rcpp::NumericVector left, Rcpp::NumericVector right);
static SEXP _rankUncertainty_getIndexIntervals_try(SEXP leftSEXP, SEXP rightSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type left(leftSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type right(rightSEXP);
    rcpp_result_gen = Rcpp::wrap(getIndexIntervals(left, right));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _rankUncertainty_getIndexIntervals(SEXP leftSEXP, SEXP rightSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_rankUncertainty_getIndexIntervals_try(leftSEXP, rightSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// getPartitionInfo
Rcpp::List getPartitionInfo(Rcpp::IntegerVector indices, Rcpp::NumericVector idxLeft, Rcpp::NumericVector idxRight);
static SEXP _rankUncertainty_getPartitionInfo_try(SEXP indicesSEXP, SEXP idxLeftSEXP, SEXP idxRightSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type indices(indicesSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type idxLeft(idxLeftSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type idxRight(idxRightSEXP);
    rcpp_result_gen = Rcpp::wrap(getPartitionInfo(indices, idxLeft, idxRight));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _rankUncertainty_getPartitionInfo(SEXP indicesSEXP, SEXP idxLeftSEXP, SEXP idxRightSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_rankUncertainty_getPartitionInfo_try(indicesSEXP, idxLeftSEXP, idxRightSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// makeCanonicalRep
Rcpp::DataFrame makeCanonicalRep(Rcpp::IntegerVector indices, Rcpp::NumericVector left, Rcpp::NumericVector right);
static SEXP _rankUncertainty_makeCanonicalRep_try(SEXP indicesSEXP, SEXP leftSEXP, SEXP rightSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type indices(indicesSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type left(leftSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type right(rightSEXP);
    rcpp_result_gen = Rcpp::wrap(makeCanonicalRep(indices, left, right));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _rankUncertainty_makeCanonicalRep(SEXP indicesSEXP, SEXP leftSEXP, SEXP rightSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_rankUncertainty_makeCanonicalRep_try(indicesSEXP, leftSEXP, rightSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}

// validate (ensure exported C++ functions exist before calling them)
static int _rankUncertainty_RcppExport_validate(const char* sig) { 
    static std::set<std::string> signatures;
    if (signatures.empty()) {
        signatures.insert("Rcpp::IntegerVector(*countPrincipalDownSets)(Rcpp::NumericVector,Rcpp::NumericVector)");
        signatures.insert("bool(*getCompatibility)(Rcpp::IntegerVector,Rcpp::NumericVector,Rcpp::NumericVector)");
        signatures.insert("Rcpp::DataFrame(*getIndexIntervals)(Rcpp::NumericVector,Rcpp::NumericVector)");
        signatures.insert("Rcpp::List(*getPartitionInfo)(Rcpp::IntegerVector,Rcpp::NumericVector,Rcpp::NumericVector)");
        signatures.insert("Rcpp::DataFrame(*makeCanonicalRep)(Rcpp::IntegerVector,Rcpp::NumericVector,Rcpp::NumericVector)");
    }
    return signatures.find(sig) != signatures.end();
}

// registerCCallable (register entry points for exported C++ functions)
RcppExport SEXP _rankUncertainty_RcppExport_registerCCallable() { 
    R_RegisterCCallable("rankUncertainty", "_rankUncertainty_countPrincipalDownSets", (DL_FUNC)_rankUncertainty_countPrincipalDownSets_try);
    R_RegisterCCallable("rankUncertainty", "_rankUncertainty_getCompatibility", (DL_FUNC)_rankUncertainty_getCompatibility_try);
    R_RegisterCCallable("rankUncertainty", "_rankUncertainty_getIndexIntervals", (DL_FUNC)_rankUncertainty_getIndexIntervals_try);
    R_RegisterCCallable("rankUncertainty", "_rankUncertainty_getPartitionInfo", (DL_FUNC)_rankUncertainty_getPartitionInfo_try);
    R_RegisterCCallable("rankUncertainty", "_rankUncertainty_makeCanonicalRep", (DL_FUNC)_rankUncertainty_makeCanonicalRep_try);
    R_RegisterCCallable("rankUncertainty", "_rankUncertainty_RcppExport_validate", (DL_FUNC)_rankUncertainty_RcppExport_validate);
    return R_NilValue;
}

static const R_CallMethodDef CallEntries[] = {
    {"_rankUncertainty_countPrincipalDownSets", (DL_FUNC) &_rankUncertainty_countPrincipalDownSets, 2},
    {"_rankUncertainty_getCompatibility", (DL_FUNC) &_rankUncertainty_getCompatibility, 3},
    {"_rankUncertainty_getIndexIntervals", (DL_FUNC) &_rankUncertainty_getIndexIntervals, 2},
    {"_rankUncertainty_getPartitionInfo", (DL_FUNC) &_rankUncertainty_getPartitionInfo, 3},
    {"_rankUncertainty_makeCanonicalRep", (DL_FUNC) &_rankUncertainty_makeCanonicalRep, 3},
    {"_rankUncertainty_RcppExport_registerCCallable", (DL_FUNC) &_rankUncertainty_RcppExport_registerCCallable, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_rankUncertainty(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
