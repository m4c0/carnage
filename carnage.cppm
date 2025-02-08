export module carnage;
import hai;
import hashley;
import jojo;
import jute;

export namespace carnage {
  struct unknown_word {};
  
  class map {
    hai::cstr file = jojo::read_cstr("cmudict/cmudict.dict");
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
