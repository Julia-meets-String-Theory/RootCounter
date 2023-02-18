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

| $\overline{K}_{B_3}^3$ | Elliptic curve | Polytope | Geometric multiplicity $\mu$ | Runtime (min) | Test result |
| :------------: | :-----------------------------------: | :------------------: | :--------------------: | :---------------: | :---------------: |
| 6 | :heavy_check_mark: | 8 | $12^3$ | 2 | [![Polytope8](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly8.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly8.yml) |
| 6 | :x: | 4 | $12^4$ | 2 | [![Polytope4](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly4.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly4.yml) |
| 6 | :x: | 134 | $12^4$ | 2 | [![Polytope134](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly134.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly134.yml) |
| 6 | :x: | 128, 130, 136, 236 | $12^4$ | 1 | [![Polytope128](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly128.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly128.yml) |
| 10 | :heavy_check_mark: | 88 | $20^{20^5}$ | 3 | [![Polytope88](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly88.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly88.yml) |
| 10 | :heavy_check_mark:  | 110 | $20^{20^5}$ | 4 | [![Polytope110](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly110.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly110.yml) |
| 10 | :heavy_check_mark: | 272, 274 | $20^{20^5}$ | 4 | [![Polytope272](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly272.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly272.yml) |
| 10 | :heavy_check_mark: | 387 | $20^{20^5}$ | 9 | [![Polytope387](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly387.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly387.yml) |
| 10 | :heavy_check_mark: | 798, 808, 810, 812 | $20^{20^5}$ | 12 | [![Polytope798](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly798.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly798.yml) |
| 10 | :x: | 254 | $20^{20^6}$ | 6 | [![Polytope254](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly254.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly254.yml) |
| 10 | :x: | 52 | $20^{20^6}$ | 7 | [![Polytope52](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly52.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly52.yml) |
| 10 | :x: | 302 | $20^{20^6}$ | 3 | [![Polytope302](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly302.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly302.yml) |
| 10 | :x: | 786 | $20^{20^6}$ | 74 | [![Polytope786](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly786.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly786.yml) |
| 10 | :x: | 762 | $20^{20^6}$ | 35 | [![Polytope762](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly762.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly762.yml) |
| 10 | :x: | 417 | $20^{20^6}$ | 34 | [![Polytope417](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly417.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly417.yml) |
| 10 | :x: | 838 | $20^{20^6}$ | 67 | [![Polytope838](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly838.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly838.yml) |
| 10 | :x: | 782 | $20^{20^6}$ | 124 | [![Polytope782](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly782.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly782.yml) |
| 10 | :x: | 377, 499, 503 | $20^{20^6}$ | 98 | [![Polytope377](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly377.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly377.yml) |
| 10 | :x: | 1348 | 239 | $20^{20^6}$ | [![Polytope1348](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly1348.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly1348.yml) |
| 10 | :x: | 882, 856 | $20^{20^6}$ | 96 | [![Polytope882](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly882.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly882.yml) |
| 10 | :x: | 1340 | $20^{20^6}$ | **> 6 hours** | :x: |
| 10 | :x: | 1879 | $20^{20^6}$ | **> 6 hours** | :x: |
| 10 | :x: | 1384 | $20^{20^6}$ | **> 6 hours** | :x: |

(Runtimes are taken from https://github.com/Julia-meets-String-Theory/RootCounter/pull/28.)
