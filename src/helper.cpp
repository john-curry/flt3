#include "helper.h"
namespace ptr_helper {
  void chk_null(void * ptr) {
    if (!ptr) {
      throw std::runtime_error("Null pointer exception thrown");
    }
  }
}
