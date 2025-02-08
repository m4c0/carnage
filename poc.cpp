#pragma leco tool

import hai;
import hashley;
import jojo;
import jute;
import print;

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

int main(int argc, char ** argv) {
  map m {};

  for (auto i = 1; i < argc; i++) {
    auto w = jute::view::unsafe(argv[i]);
    putln(m[w]);
  }
}
