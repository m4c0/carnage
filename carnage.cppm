#pragma leco add_resource "cmudict/cmudict.dict"
export module carnage;
import hai;
import hashley;
import jute;
import sires;

export namespace carnage {
  struct unknown_word {};
  
  class map {
    hai::cstr file = sires::jojo_cstr("cmudict.dict");
    hashley::niamh w2p { 101113 };
  
  public:
    map() {
      jute::view lines { file };
      while (lines.size()) {
        auto [line, rest] = lines.split('\n');
        lines = rest;
  
        auto [word, phonemes] = line.split(' ');
        w2p[word] = phonemes.begin() - file.begin();
      }
    }
  
    [[nodiscard]] auto operator[](jute::view w) {
      auto n = w2p[w];
      if (!n) throw unknown_word {};
      return jute::view { file }.subview(n).after.split('\n').before;
    }
  };
}
