#pragma once

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <new>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

namespace todo
{
    using u8 = std::uint8_t;
    using u16 = std::uint16_t;
    using u32 = std::uint32_t;
    using u64 = std::uint64_t;
    using usize = std::uintptr_t;

    using i8 = std::int8_t;
    using i16 = std::int16_t;
    using i32 = std::int32_t;
    using i64 = std::int64_t;
    using isize = std::intptr_t;

    using f32 = std::float_t;
    using f64 = std::double_t;
}

static inline auto operator<<(std::ostream& stream, const std::chrono::time_point<std::chrono::system_clock>& now) -> std::ostream&
{
    auto time = std::chrono::system_clock::to_time_t(now);
    stream << std::put_time(std::localtime(&time), "%d.%m.%Y %H:%M:%S");
    return stream;
}
