#include <benchmark/benchmark.h>

#include <vector>
#include <string>
#include <exception>
#include <cstdint>

using namespace std;

int doSome() {
    if (std::rand() < 0) {
        throw 2;
    }
    return 1;
}

static void TryCatch(benchmark::State& state) {
    for (auto _ : state) {
        try {
            benchmark::DoNotOptimize(doSome());
        } catch (std::exception &e) {

        }
    }
}

BENCHMARK(TryCatch);

static void NoTryCatch(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(doSome());
    }
}

BENCHMARK(NoTryCatch);

BENCHMARK_MAIN();
