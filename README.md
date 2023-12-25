# 1. Brief Project Description:

Goal of the Project:
The goal of the project is to address high load latency caused by deep cache hierarchies and slow main memory. The proposed solution involves cache-level prediction to complement prefetchers. By predicting which memory hierarchy level a load will access, the project aims to initiate memory loads earlier, reducing cycles and improving single-thread performance.

Project Source (PDF Paper):
The project is based on the research paper titled "Reducing Load Latency with Cache Level Prediction" by Majid Jalili and Mattan Erez from The University of Texas at Austin. The authors can be contacted at majid,mattan.erezg@utexas.edu.

Popular Levels Detector

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
