#ifndef PARAMS_HPP
#define PARAMS_HPP

namespace pcd {
  struct FilteringParams {
    int d = 9;
    double sigmaColor = 75;
    double sigmaSpace = 75;
  };

  struct EdgeParams {
    double lowThreshold = 50;
    double highThreshold = 150;
  };
}

#endif