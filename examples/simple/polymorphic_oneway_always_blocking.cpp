#include <experimental/thread_pool>
#include <iostream>

namespace execution = std::experimental::execution;
using std::experimental::static_thread_pool;

using executor = execution::executor<
  execution::oneway_t,
  execution::single_t,
  execution::blocking_t::always_t>;

int main()
{
  static_thread_pool pool{1};
  executor ex = execution::require(pool.executor(), execution::blocking.always);
  ex.execute([]{ std::cout << "we made it\n"; });
}
