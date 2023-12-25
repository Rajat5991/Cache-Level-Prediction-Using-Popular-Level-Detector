#pragma once

#include <cstdint>
#include <string>
// Declare l2_counter as extern (it will be defined in counter.cpp)
 extern int32_t l2_counter;

// Declare l3_counter as extern (it will be defined in counter.cpp)
 extern int32_t l3_counter;

// Declare mem_counter as extern (it will be defined in counter.cpp)
 extern int32_t mem_counter;
 extern int32_t skip_l2_cache;
 extern int32_t skip_l3_cache;
 extern std::string originalString;

// Declare l2_ref_counter as a reference to l2_counte
 extern int32_t& l2_ref_counter;
// Declare l3_ref_counter as a reference to l2_counte
 extern int32_t& l3_ref_counter;
// Declare mem_ref_counter as a reference to l2_counte
 extern int32_t& mem_ref_counter;
 extern int32_t& skip_l2_ref_cache;
 extern int32_t& skip_l3_ref_cache;
 // Declare to access cache name
 extern std::string& cache_name;
