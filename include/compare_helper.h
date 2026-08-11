#ifndef LEETCODE_COMPARE_HELPER_H
#define LEETCODE_COMPARE_HELPER_H

#include <algorithm>
#include <iterator>
#include <ranges>

namespace compareHelper {

template <typename Container>
bool equalIgnoreOrder(const Container& lhs, const Container& rhs) {
    if (lhs.size() != rhs.size()) return false;

    Container sorted_lhs = lhs;
    Container sorted_rhs = rhs;
    using Element = typename Container::value_type;

    if constexpr (requires(Element element) {
                      { element.begin() } -> std::input_or_output_iterator;
                      { element.end() } -> std::input_or_output_iterator;
                  }) {
        for (auto& element : sorted_lhs) std::ranges::sort(element);
        for (auto& element : sorted_rhs) std::ranges::sort(element);
    }

    std::ranges::sort(sorted_lhs);
    std::ranges::sort(sorted_rhs);
    return sorted_lhs == sorted_rhs;
}

}  // namespace compareHelper

#endif  // LEETCODE_COMPARE_HELPER_H
