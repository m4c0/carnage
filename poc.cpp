#pragma leco app

import carnage;
import jute;
import print;

int main(int argc, char ** argv) {
  carnage::map m {};

  for (auto i = 1; i < argc; i++) {
    auto w = jute::view::unsafe(argv[i]);
    putln(m[w]);
  }
}
