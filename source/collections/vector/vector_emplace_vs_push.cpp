#include <benchmark/benchmark.h>

#include <vector>
#include <string>

using namespace std;

class TestClass {
public:
    TestClass() {

    }

private:

};

static void BM_StringCreation(benchmark::State& state) {
    std::vector<int> data;
    for (auto _ : state) {

    }
}

BENCHMARK(BM_StringCreation);

BENCHMARK_MAIN();
