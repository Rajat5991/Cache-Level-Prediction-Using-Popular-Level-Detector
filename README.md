# 1. Brief Project Description:

Goal of the Project:
The goal of the project is to address high load latency caused by deep cache hierarchies and slow main memory. The proposed solution involves cache-level prediction to complement prefetchers. By predicting which memory hierarchy level a load will access, the project aims to initiate memory loads earlier, reducing cycles and improving single-thread performance.

Project Source (PDF Paper):
The project is based on the research paper titled "Reducing Load Latency with Cache Level Prediction" by Majid Jalili and Mattan Erez from The University of Texas at Austin. The authors can be contacted at majid,mattan.erezg@utexas.edu.

Popular Levels Detector:

We use 3 counters, one per cache level and main memory. Upon a hit at a level the corresponding counter is incremented by 1 and others are decremented by 1. This helps to rapidly find popular levels and prevents counter saturation. When a prediction is required, candidates are selected as follows. The counters are sorted and the topmost is picked as the first candidate. If its counter is higher than a threshold, then only this level is selected as the level to look up. Otherwise, the level with the second highest counter is also considered to be a possible destination (two parallel lookup targets). If again the sum of the first and the second counters does not reach a predefined threshold, the third level is also included (three parallel lookup targets).

Simulator Used:
The zsim simulator is employed for conducting experiments in the project. The simulator models a 3-level cache hierarchy and is used to evaluate level prediction with an advanced prefetch scheme.

# 2. Project Structure
We have maintained the same hierarchy as that of zsim simulator code that we used for the academic assignments. The structure is as follows.
1. The source folder contains all the necessary files such as init.cpp, cache.cpp, coherence_ctrl.cpp, timing_cache.cpp.
2. The configs folder contains information about the benchmarks that we are using to simulate the results.
3. We have the output files generated in the zsim/output folder.
4. Hirarchy: The last-level cache (LLC) is represented by a single root in the tree-structured cache system, and intermediate nodes stand in for intermediate level caches (e.g. L2). The processor and the attached private L1d and L1i cache are located at the leaf level. 

# 3. Libraries
Library details are provided in a separate readme file placed inside zsim folder.

### I. Environemnt setup

Everytime you want to build or run zsim, you need to setup the environment variables first.

```
$ source setup_env
```

##### II. Compile zsim

```
$ cd zsim
$ scons -j4
```

##### III. Launch a test to run

```
./build/opt/zsim tests/simple.cfg
```
# 4. Benchmarks

  Our evaluation included a diverse set of benchmarks:
  
PARSEC: blackscholes, bodytrack, canneal, dedup, fluidanimate, streamcluster, swaptions, x264.

# 5. Result Analysis

The approach involves evaluating cache-level prediction frameworks, with a shift from the gem5 simulator used in the original study to the zsim simulator for replication. While the original research employed a mix of benchmarks including SPEC CPU 2017, GAPBS (pr, tc, cc, bfs, and bc), NAS (cg, ft, is, mg, and ua), and additional benchmarks like bmt, hpcg, stream-copy, and gups, our analysis focuses on PARSEC benchmarks: blackscholes, bodytrack, canneal, dedup, fluidanimate, streamcluster, swaptions, x264. Unlike the original paper, we omit prefetchers in our simulation. The advanced zsim timing cache is also not utilized. The inclusion of the level predictor resulted in an average speedup of 1.04. However, it's worth noting that the original paper reported superior performance outcomes compared to our findings.

The provided data compares the Cycles Per Instruction (CPI) for various benchmarks across different instances with and without the cache-level predictor. A comprehensive analysis is presented below:

1. bodytrack:
   
The level predictor consistently reduces CPI across instances (westmere-0 to westmere-6) except for instance westmere-5. In westmere-5, there is an unexpected increase in CPI with the level predictor compared to without it. Overall, the level predictor is effective in reducing cycles per instruction, indicating improved performance for most instances.

2. blackscholes:
   
The level predictor provides a notable reduction in CPI for instances westmere-0, westmere-2, westmere-3, westmere-4, westmere-6, and westmere-7. Instances westmere-1 and westmere-5, however, show an increase in CPI with the level predictor. The predictor is beneficial in enhancing performance for several instances, but its impact varies.

3. x264: 

The level predictor demonstrates a consistent reduction in CPI for instances westmere-0, westmere-2, westmere-3, westmere-4, westmere-6, and westmere-7. Instances westmere-1 and westmere-5, on the other hand, show an increase in CPI with the level predictor. Overall, the predictor is effective in lowering cycles per instruction, contributing to improved performance in most instances.

4. streamcluster:

The level predictor provides a reduction in CPI for instances westmere-0, westmere-1, westmere-2, westmere-4, westmere-5, and westmere-6. Instances westmere-3 and westmere-7, however, show an increase in CPI with the level predictor. The impact of the predictor varies across different instances, being beneficial in some cases.

5. canneal:

The level predictor demonstrates a CPI reduction for instances westmere-0, westmere-2, westmere-3, westmere-4, westmere-5, westmere-6, and westmere-7. Instances westmere-1, however, show an increase in CPI with the level predictor. Overall, the predictor contributes to a reduction in cycles per instruction, indicating improved performance.

6. fluidanimate:

The level predictor leads to a CPI reduction for instances westmere-0, westmere-1, westmere-2, westmere-3, westmere-4, westmere-5, and westmere-7. Instance westmere-6, however, shows an increase in CPI with the level predictor. Generally, the predictor is effective in improving performance across most instances.

Overall Summary:

The cache-level predictor demonstrates effectiveness in reducing CPI and improving performance across various benchmarks and instances. However, there are instances where the predictor leads to an unexpected increase in CPI, suggesting that its impact is workload dependent. Further investigation and tuning may be required to optimize the predictor's performance for specific workloads and instances.

<img width="568" alt="image" src="https://github.com/Rajat5991/Cache-Level-Prediction-Using-Popular-Level-Detector/assets/154459536/825aab8e-4ef3-4c23-a71b-974f8d9fce3d">

<img width="500" alt="image" src="https://github.com/Rajat5991/Cache-Level-Prediction-Using-Popular-Level-Detector/assets/154459536/d31a00b4-0208-4eb4-a176-7358c1b22ade">

# 6. Conclusion: 

We observed a cache level predictor enhances the lookup strategy in multiple-cache setting. This technique filters unnecessary accesses to intermediate levels, and thus reduces the cumulative miss latency. The proposed system enhances the CPI by 4% compared to the baseline.


