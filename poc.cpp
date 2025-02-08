#pragma leco tool

import hai;
import hashley;
import jojo;
import jute;
import print;

struct unknown_word {};

int main(int argc, char ** argv) {
  hai::cstr file = jojo::read_cstr("cmudict/cmudict.dict");
  hashley::niamh w2p { 101113 };

  jute::view lines { file };
  while (lines.size()) {
    auto [line, rest] = lines.split('\n');
    lines = rest;

    auto [word, phonemes] = line.split(' ');
    w2p[word] = phonemes.begin() - file.begin();
  }

  for (auto i = 1; i < argc; i++) {
    auto w = jute::view::unsafe(argv[i]);
    auto n = w2p[w];
    if (!n) throw unknown_word {};
    auto p = jute::view { file }.subview(n).after.split('\n').before;
    putln(p);
  }
}
