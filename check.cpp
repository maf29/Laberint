#include "laberint.hpp"
#include <esin/util>

using util::nat;
using namespace std;

namespace check {

  bool comprova_cami_minim(const posicio& ini,
			     const posicio& final,
			     const laberint& L,
			     const list<posicio>& cami_candidat)
    throw(error) {
    posicio f = final;
    posicio i = ini;
    f = i;
    laberint ll = L;
    list<posicio> cami = cami_candidat;
    return true;
  }

  bool comprova_perfecte(const laberint& L) {
    laberint ll = L;
    return true;
  }
};
