# RootCounter

Originally, this code was and currently still is available in the [ToricVarieties_project](https://github.com/homalg-project/ToricVarieties_project). To make this tool available to other computer algebra systems, the code has been dispatch to this repository at the beginning of 2023.

# Code coverage

[![codecov](https://codecov.io/gh/Julia-meets-String-Theory/RootCounter/branch/master/graph/badge.svg?token=U7F50XH52P)](https://codecov.io/gh/Julia-meets-String-Theory/RootCounter)

# General tests

| Description | Test result | Runtime (min) |
| ----------- | ------ | ------ |
| Basic tests | [![BasicTests](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/BasicTests.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/BasicTests.yml)| 2 |
| Simple root counting | [![SimpleRootCounting](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/SimpleRootCounting.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/SimpleRootCounting.yml) | 2 |


# Root counting for QSMs

| $\overline{K}_{B_3}^3$ | Elliptic curve | Polytope | Runtime (min) | Test result |
| ------------ | ----------------------------------- | ------------------ | -------------------- | --------------- |
| 6 | :heavy_check_mark: | 8 | 2 | [![Polytope8](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly8.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly8.yml) |
---
| 6 | :x: | 4 | 2 | [![Polytope4](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly4.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly4.yml) |
| 6 | :x: | 134 | 2 | [![Polytope134](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly134.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly134.yml) |
| 6 | :x: | 128, 130, 136, 236 | 1 | [![Polytope128](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly128.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly128.yml) |
---
| 10 | :heavy_check_mark: | 88 | 3 | [![Polytope88](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly88.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly88.yml) |
| 10 | :heavy_check_mark:  | 110 | 4 | [![Polytope110](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly110.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly110.yml) |
| 10 | :heavy_check_mark: | 272, 274 | 4 | [![Polytope272](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly272.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly272.yml) |
| 10 | :heavy_check_mark: | 387 | 9 | [![Polytope387](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly387.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly387.yml) |
| 10 | :heavy_check_mark: | 798, 808, 810, 812 | 12 | [![Polytope798](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly798.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly798.yml) |
---
| 10 | :x: | 254 | 6 | [![Polytope254](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly254.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly254.yml) |
| 10 | :x: | 52 | 7 | [![Polytope52](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly52.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly52.yml) |
| 10 | :x: | 302 | 3 | [![Polytope302](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly302.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly302.yml) |
| 10 | :x: | 786 | 74 | [![Polytope786](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly786.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly786.yml) |
| 10 | :x: | 762 | 35 | [![Polytope762](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly762.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly762.yml) |
| 10 | :x: | 417 | 34 | [![Polytope417](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly417.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly417.yml) |
| 10 | :x: | 838 | 67 | [![Polytope838](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly838.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly838.yml) |
| 10 | :x: | 782 | 124 | [![Polytope782](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly782.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly782.yml) |
| 10 | :x: | 377, 499, 503 | 98 | [![Polytope377](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly377.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly377.yml) |
| 10 | :x: | 1348 | 239 | [![Polytope1348](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly1348.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly1348.yml) |
| 10 | :x: | 882, 856 | 96 | [![Polytope882](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly882.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly882.yml) |
| 10 | :x: | 1340 | **> 6 hours** | [![Polytope1340](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly1340.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly1340.yml) |
| 10 | :x: | 1879 | **> 6 hours** | [![Polytope1879](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly1879.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly1879.yml) |
| 10 | :x: | 1384 | **> 6 hours** | [![Polytope1384](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly1384.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly1384.yml) |

(Runtimes are taken from https://github.com/Julia-meets-String-Theory/RootCounter/pull/28.)
