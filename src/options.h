#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <iostream>
#include <boost/program_options.hpp>

namespace options {
  using namespace std;
  namespace po = boost::program_options;

  void initOptions() {
    cout << "initializing options" << endl;
  }
}

#endif
