#include <iostream>
#include "Geometry.h"

double uniform() {
    return double(rand()) / RAND_MAX;
}

Vector3D rand_vector() {
    return {uniform(), uniform(), uniform()};
}

int main() {
    // tests with intersection
    const int NUM_TESTS_OK = 100;
    bool flag = true;
    for (int i = 0; i < NUM_TESTS_OK; ++i) {
        Vector3D center = rand_vector();
        Vector3D delta1 = rand_vector();
        Vector3D delta2 = rand_vector();
        Segment3D first{center - delta1, center + delta1};
        Segment3D second{center - delta2, center + delta2};
        std::optional<Vector3D> result = Intersect(first, second);
        if (!result.has_value()) {
            std::cout << "FAILED" << std::endl;
            std::cout << std::endl;
        } else {
            if (result.value() != center) {
                flag = false;
                std::cout << "FAILED" << std::endl;
                std::cout << "expected: " << center << std::endl;
                std::cout << "given: " << result.value() << std::endl;
                std::cout << std::endl;
            }
        }

    }
    if (flag) {
        std::cout << "OK" << std::endl;
    }

    // dummy example

    // Don't intersection
    Segment3D segment1{{0, 0, 1},
                       {37, 2, 5}}, segment2{{0, 0, 0},
                                            {1, 2, 5}};

    std::optional<Vector3D> result_vector = Intersect(segment1, segment2);
    if (result_vector.has_value()) {
        std::cout << "Intersection: " << result_vector.value() << std::endl;
    } else {
        std::cout << "Don't intersection" << std::endl;
    }
    return 0;
}
