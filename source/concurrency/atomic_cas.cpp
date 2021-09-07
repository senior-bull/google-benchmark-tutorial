#include <benchmark/benchmark.h>

#include <vector>
#include <string>
#include <atomic>

using namespace std;

std::atomic<int> a;

static void AtomicStore_Relaxed(benchmark::State& state) {
    for (auto _ : state) {
        a.store(5, std::memory_order_relaxed);
    }
}

BENCHMARK(AtomicStore_Relaxed)->Threads(3);

static void AtomicStore_SequentialConsistency(benchmark::State& state) {
    for (auto _ : state) {
        a.store(5, std::memory_order_seq_cst);
    }
}

BENCHMARK(AtomicStore_SequentialConsistency)->Threads(3);


BENCHMARK_MAIN();
