#include "counter.h"

// Define l2_counter
int32_t l2_counter = 0;


// Define l3_counter
int32_t l3_counter = 0;
// Define mem_counter
int32_t mem_counter = 0;
int32_t skip_l2_cache = 0;
int32_t skip_l3_cache = 0;

// Define l2_ref_counter as a reference to l2_counter
int32_t& l2_ref_counter = l2_counter;


// Define l2_ref_counter as a reference to l2_counter
int32_t& l3_ref_counter = l3_counter;

// Define mem_ref_counter as a reference to l2_counter
int32_t& mem_ref_counter = mem_counter;

int32_t& skip_l2_ref_cache = skip_l2_cache;
int32_t& skip_l3_ref_cache = skip_l3_cache;

std::string originalString = "l1i-0";
std::string& cache_name = originalString;
