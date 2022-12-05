#include <cxxopts/cxxopts.h>
#include <iostream>

#include "../lib/add.h"

namespace add {

    struct config {
        int a;
        int b;
    };

    void print_help(cxxopts::Options& opts, int exit_code = 0) {
        std::ostream& os = (exit_code ? std::cerr : std::cout);
        os << opts.help({""}) << std::endl;
        exit(exit_code);
    }

    cxxopts::Options set_options() {

        cxxopts::Options opts("add","Adds two numbers.");

        opts.add_options()
                ("a,param-a", "first parameter", cxxopts::value<int>(),"A")
                ("b,param-b", "second parameter", cxxopts::value<int>(), "B")
                ("h,help", "print this help message");

        return opts;
    }

    config parse_options(cxxopts::Options opts, int argc, char** argv) {

        config config{};

        auto parsed = opts.parse(argc, argv);

        if (parsed.count("a")) {
            config.a = parsed["a"].as<int>();
        } else {
            print_help(opts, 1);
        }

        if (parsed.count("b")) {
            config.b = parsed["b"].as<int>();
        } else {
            print_help(opts, 1);
        }

        return config;
    }
}

int main(int argc, char** argv) {

    auto config = add::parse_options(add::set_options(), argc, argv);

    std::cout << config.a << " + " << config.b << " = "
              << add::add(config.a, config.b) << std::endl;

    return 0;
}
