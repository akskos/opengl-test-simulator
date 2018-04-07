#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <iostream>
#include <boost/program_options.hpp>

#include "config.h"

namespace options {
  using namespace std;

  namespace {
    namespace po = boost::program_options;

    po::options_description produceDescription() {
      po::options_description desc("Allowed options");
      desc.add_options()
         ("help", "produce help message")
         ("size", po::value<int>(), "set window size in pixels")
         ("fov", po::value<float>(), "set field of view in degrees")
      ;
      return desc;
    } 

    po::variables_map initParser(const int argc, const char** argv) {
      po::variables_map vm;
      po::options_description desc = produceDescription();
      po::store(po::parse_command_line(argc, argv, desc), vm);
      po::notify(vm);
      return vm;
    }
  }

  void parseOptions(const int argc, const char** argv) {
    po::variables_map vm = initParser(argc, argv);
    if (vm.count("help")) {
      cout << produceDescription() << endl;
    }
    if (vm.count("size")) {
      int size = vm["size"].as<int>();
      Config::setWindowSize(size);
    }
    if (vm.count("fov")) {
      float fov = vm["fov"].as<float>();
      Config::setFov(fov);
    }
  }
}

#endif
