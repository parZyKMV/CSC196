#pragma once

#include <random>

namespace viper::random {

    /// <summary>
    /// Returns a reference to a static Mersenne Twister generator initialized with a random seed.
    /// </summary>
    /// <returns>A reference to a std::mt19937 generator.</returns>
    inline std::mt19937& generator() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return gen;
    }

    /// <summary>
    /// Seeds the random number generator with the specified value.
    /// </summary>
    /// <param name="value">The seed value.</param>
    inline void seed(unsigned int value) {
        generator().seed(value);
    }

    /// <summary>
    /// Generates a random integer in the range [min, max].
    /// </summary>
    /// <param name="min">Minimum value (inclusive).</param>
    /// <param name="max">Maximum value (inclusive).</param>
    /// <returns>A random integer between min and max.</returns>
    inline int getInt(int min, int max) {
        std::uniform_int_distribution<> dist(min, max);
        return dist(generator());
    }

    /// <summary>
    /// Generates a random integer in the range [0, max - 1].
    /// </summary>
    /// <param name="max">Upper bound (exclusive).</param>
    /// <returns>A random integer from 0 to max - 1.</returns>
    inline int getInt(int max) {
        return getInt(0, max - 1);
    }

    /// <summary>
    /// Generates a random integer using the full range of the generator.
    /// </summary>
    /// <returns>A random integer.</returns>
    inline int getInt() {
        static std::uniform_int_distribution<> dist;
        return dist(generator());
    }

    /// <summary>
    /// Generates a random real number in the range [min, max).
    /// </summary>
    /// <typeparam name="T">The floating-point type of the generated number. Defaults to float.</typeparam>
    /// <param name="min">Minimum value (inclusive).</param>
    /// <param name="max">Maximum value (exclusive).</param>
    /// <returns>A random real number of type T.</returns>
    template <typename T = float>
    inline T getReal(T min, T max) {
        std::uniform_real_distribution<T> dist(min, max);
        return dist(generator());
    }

    /// <summary>
    /// Generates a random real number in the range [0, max).
    /// </summary>
    /// <typeparam name="T">The floating-point type. Defaults to float.</typeparam>
    /// <param name="max">Maximum value (exclusive).</param>
    /// <returns>A random real number of type T.</returns>
    template <typename T = float>
    inline T getReal(T max) {
        return getReal(static_cast<T>(0), static_cast<T>(max));
    }

    /// <summary>
    /// Generates a random real number in the range [0, 1).
    /// </summary>
    /// <typeparam name="T">The floating-point type. Defaults to float.</typeparam>
    /// <returns>A random real number of type T in the range [0, 1).</returns>
    template <typename T = float>
    inline T getReal() {
        static std::uniform_real_distribution<T> dist(static_cast<T>(0), static_cast<T>(1));
        return dist(generator());
    }

    /// <summary>
    /// Generates a random boolean value with 50% probability.
    /// </summary>
    /// <returns>True or false with equal probability.</returns>
    inline bool getBool() {
        static std::bernoulli_distribution dist(0.5);
        return dist(generator());
    }
}
