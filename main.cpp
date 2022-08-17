#include <fmt/format.h>
#include <fmt/ostream.h>
#include "WriterMonad.h"

using namespace Writer;

int main(){
    auto a = NumberHolder(2);

    auto b = runWithLogs(2, square);
    auto c = runWithLogs(b, addOne);
    auto d = runWithLogs(c, square);
    auto e = runWithLogs(runWithLogs(c, square),square);

    fmt::print("{}", e);

    auto m = NumberHolder(4)
                            .runWithLogs(square)
                            .runWithLogs(addOne)
                            .runWithLogs(addOne)
                            .runWithLogs(square)
                            .runWithLogs(into2);

    fmt::print("{}", m);
}
