//
// Created by kumar on 7/9/2022.
//

#include <vector>
#include <functional>

#ifndef AGAMA_WRITERMONAD_H
#define AGAMA_WRITERMONAD_H



namespace Writer {
    class NumberHolder;
    using vFunctionType = std::function<NumberHolder(int)>;
    class NumberHolder{
    public:
        int num;
        std::vector<std::string > logs;

        NumberHolder(int n) : num(n) {}

        NumberHolder(int n, std::vector<std::string> l){
            num = n;
            logs.insert(logs.end(), l.begin(), l.end());
        }

        friend std::ostream& operator<<(std::ostream& os, const NumberHolder& nh){
            os << "num: " << nh.num << "\n";
            os << "logs {\n";
            for(auto& l:nh.logs){
                os << "\t" << l << "\n";
            }
            os << "}\n";

            return os;
        }

        NumberHolder runWithLogs(vFunctionType transform) {
            auto newNumberHolder = transform(num);
            newNumberHolder.logs.insert(newNumberHolder.logs.begin(), logs.begin(), logs.end());

            return NumberHolder(
                    newNumberHolder.num,
                    newNumberHolder.logs
            );
        }
    };


    NumberHolder square(int x) {
        return NumberHolder(x * x, {fmt::format("{}^2 = {}", x, x*x)});
    }

    NumberHolder addOne(int x) {
        return NumberHolder(x + 1, {fmt::format("{}+1 = {}", x, x+1)});
    }

    NumberHolder into2(int x){
        return NumberHolder(2 * x, {fmt::format("{}*2 = {}", x, 2*x)});
    }
    

    NumberHolder runWithLogs(NumberHolder input, vFunctionType transform){
        auto newNumberHolder = transform(input.num);
        newNumberHolder.logs.insert(newNumberHolder.logs.begin(), input.logs.begin(), input.logs.end());

        return NumberHolder(
                newNumberHolder.num,
                newNumberHolder.logs
                );
    }
}

#endif //AGAMA_WRITERMONAD_H
