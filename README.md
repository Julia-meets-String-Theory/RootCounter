# RootCounter

Originally, this code was and currently still is available in the [ToricVarieties_project](https://github.com/homalg-project/ToricVarieties_project). To make this tool available to other computer algebra systems, the code has been moved to this repository at the beginning of 2023. For more background, see e.g. [this article](https://arxiv.org/pdf/2205.00008.pdf) and references therein.

# Code coverage

[![codecov](https://codecov.io/gh/Julia-meets-String-Theory/RootCounter/branch/master/graph/badge.svg?token=U7F50XH52P)](https://codecov.io/gh/Julia-meets-String-Theory/RootCounter)

# General tests

| Description | Test result | Runtime (min) |
| ----------- | ------ | ------ |
| Basic tests | [![BasicTests](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/BasicTests.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/BasicTests.yml)| 2 |
| Simple root counting | [![SimpleRootCounting](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/SimpleRootCounting.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/SimpleRootCounting.yml) | 2 |


# Root counting for QSMs

| Polytope | $\overline{K}_{B_3}^3$ | Elliptic curve | Geometric multiplicity $\mu$ | Total number of roots | Estimate for number of triangulations $T$ | Upper bound for number of configurations | Runtime (min) | Test result |
| :------------: | :------------: | :------------: | :------------: | :------------: | :------------: | :------------: | :------------: | :------------: |
| 8 | 6 | :heavy_check_mark: | $12^3$ | $12^8$ | $3.867 \times 10^{13} \leq T \leq 2.828 \times 10^{16}$ | $10^{24}$ | 2 | [![Polytope8](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly8.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly8.yml) |
| 4 | 6 | :x: | $12^4$ | $12^8$ | $3.188 \times 10^{11}$ | $10^{20}$ | 2 | [![Polytope4](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly4.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly4.yml) |
| 134 | 6 | :x: | $12^4$ | $12^8$ | $7.538 \times 10^{10}$ | $10^{19}$ | 2 | [![Polytope134](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly134.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly134.yml) |
|  128, 130, 136, 236 | 6 | :x: | $12^4$ | $12^8$ | $3.217 \times 10^{11}$ | $10^{20}$ | 1 | [![Polytope128](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly128.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly128.yml) |
| 88 | 10 | :heavy_check_mark: | $20^5$ | $20^{12}$ | $5.231 \times 10^{10} \leq T \leq 1.246 \times 10^{14}$ | $10^{30}$ | 3 | [![Polytope88](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly88.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly88.yml) |
| 110 | 10 | :heavy_check_mark: | $20^{5}$ | $20^{12}$ | $5.239 \times 10^{8}$ | $10^{24}$ | 4 | [![Polytope110](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly110.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly110.yml) |
| 272, 274 | 10 | :heavy_check_mark: | $20^{5}$| $20^{12}$ | $3.212 \times 10^{12} \leq T \leq 2.481 \times 10^{15}$ | $10^{31}$ | 4 | [![Polytope272](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly272.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly272.yml) |
| 387 | 10 | :heavy_check_mark: | $20^{5}$ | $20^{12}$ | $6.322 \times 10^{10} \leq T \leq 6.790 \times 10^{12}$ | $10^{28}$ | 9 | [![Polytope387](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly387.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly387.yml) |
| 798, 808, 810, 812 | 10 | :heavy_check_mark: | $20^{5}$ | $20^{12}$ | $1.672 \times 10^{10} \leq T \leq 2.515 \times 10^{13}$ | $10^{29}$ | 12 | [![Polytope798](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly798.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly798.yml) |
| 254 | 10 | :x: | $20^{20^6}$ | $20^{12}$ | $1.568 \times 10^{10}$ | $10^{26}$ | 6 | [![Polytope254](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly254.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly254.yml) |
| 52 | 10 | :x: | $20^{6}$ | $20^{12}$ | $1.248 \times 10^{8}$ | $10^{24}$ | 7 | [![Polytope52](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly52.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly52.yml) |
| 302 | 10 | :x: | $20^{6}$ | $20^{12}$ | $5.750 \times 10^{7}$ | $10^{23}$ | 3 | [![Polytope302](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly302.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly302.yml) |
| 786 | 10 | :x: | $20^{6}$ | $20^{12}$ | $9.810 \times 10^{8}$ | $10^{24}$ | 74 | [![Polytope786](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly786.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly786.yml) |
| 762 | 10 | :x: | $20^{6}$ | $20^{12}$ | $1.087 \times 10^{11} \leq T \leq 2.854 \times 10^{13}$ | $10^{30}$ | 35 | [![Polytope762](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly762.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly762.yml) |
| 417 | 10 | :x: | $20^{6}$ | $20^{12}$ | $1.603 \times 10^{9}$ | $10^{25}$ | 34 | [![Polytope417](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly417.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly417.yml) |
| 838 | 10 | :x: | $20^{6}$ | $20^{12}$ | $4.461 \times 10^{9}$ | $10^{25}$ | 67 | [![Polytope838](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly838.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly838.yml) |
| 782 | 10 | :x: | $20^{6}$ | $20^{12}$ | $3.684 \times 10^{9}$ | $10^{25}$ | 124 | [![Polytope782](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly782.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly782.yml) |
| 377, 499, 503 | 10 | :x: | $20^{6}$ | $20^{12}$ | $4.461 \times 10^{9}$ | $10^{25}$ | 98 | [![Polytope377](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly377.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly377.yml) |
| 1348 | 10 | :x: | $20^{6}$ | $20^{12}$ | $4.285 \times 10^{9}$ | $10^{25}$ | 239 | [![Polytope1348](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly1348.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly1348.yml) |
| 882, 856 | 10 | :x: | $20^{6}$ | $20^{12}$ | $3.180 \times 10^{9}$ | $10^{25}$ | 96 | [![Polytope882](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly882.yml/badge.svg)](https://github.com/Julia-meets-String-Theory/RootCounter/actions/workflows/Poly882.yml) |
| 1340 | 10 | :x: | $20^{6}$ | $20^{12}$ | $4.496 \times 10^{9}$ | $10^{25}$ | **> 6 hours** | :x: |
| 1879 | 10 | :x: | $20^{6}$ | $20^{12}$ | $4.461 \times 10^{9}$ | $10^{25}$ | **> 6 hours** | :x: |
| 1384 | 10 | :x: | $20^{6}$ | $20^{12}$ | $7.040 \times 10^{9}$ | $10^{25}$ | **> 6 hours** | :x: |

(Runtimes are taken from https://github.com/Julia-meets-String-Theory/RootCounter/pull/28.)
