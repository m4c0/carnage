#pragma leco tool

import jojo;
import print;

int main() {
  auto dict_file = jojo::read_cstr("cmudict/cmudict.dict");
  putln(dict_file.begin());

}
