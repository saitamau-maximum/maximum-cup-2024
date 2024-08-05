# Grundy 数の一般項の証明

以下、体力 H のスライムの Grundy 数を $g(H)$ と表現する。( $g(0) = 0, D$ は正の整数 ) \
三段階に分けて一般項を証明。

1. $D = \infty$ の場合 ($k$ は非負整数)

- $g(4k+1) = 4k+1$
- $g(4k+2) = 4k+2$
- $g(4k+3) = 4k+4$
- $g(4k+4) = 4k+3$

<br>

2. $D \neq \infty$ の場合に $g(0)$ を除いて先頭 $D + D \ \% \ 2$ 項目まで 1 に従う

<br>

3. 以降 $D + D \ \% \ 2 = X$ とおく。以下が成立することを示す ※ $s, t$ は非負整数

- $D \equiv 0 \pmod 2$ の場合 :

  - $g(X(t+1) + 1) = 0$
  - $g(X(t+1) + 2) = D+1$
  - $g(X(t+1) + 2 + 4s+1)=4s+1$
  - $g(X(t+1) + 2 + 4s+2)=4s+2$
  - $g(X(t+1) + 2 + 4s+3)=4s+4$
  - $g(X(t+1) + 2 + 4s+4)=4s+3$
  - s に関連する項は $D$ 項分だけ従う

- $D \equiv 1 \pmod 2$ の場合
  - $g(X(t+1) + 1) = 0$
  - $g(X(t+1) + 1 + 4s+1)=4s+2$
  - $g(X(t+1) + 1 + 4s+2)=4s+1$
  - $g(X(t+1) + 1 + 4s+3)=4s+3$
  - $g(X(t+1) + 1 + 4s+4)=4s+4$
  - s に関連する項は $D$ 項分だけ従う

<br>

## 1. の証明

$D = \infty$ の場合 ($k$ は非負整数)

- $g(4k+1)=4k+1$
- $g(4k+2)=4k+2$
- $g(4k+3)=4k+4$
- $g(4k+4)=4k+3$

が成り立つことを数学的帰納法で証明する。\
なお、 $g(0) = 0$ であることは明らかとして利用する。

### (ⅰ) $k = 0$ の場合

$$
\begin{align*}
  g(1) &= \text{mex}\lbrace g(0) \rbrace \\
       &= \text{mex}\lbrace 0 \rbrace \\
       &= 1 \ (= 4 \times 0 + 1)
\end{align*}
$$

$$
\begin{align*}
  g(2) &= \text{mex}\lbrace g(0), g(1), g(1) \oplus g(1) \rbrace \\
       &= \text{mex}\lbrace 0, 1, 0 \rbrace \\
       &= 2 \ (= 4 \times 0 + 2)
\end{align*}
$$

$$
\begin{align*}
  g(3) &= \text{mex}\lbrace g(0), g(1), g(2), g(1) \oplus g(2) \rbrace \\
       &= \text{mex}\lbrace 0, 1, 2, 1 \oplus 2 \rbrace \\
       &= \text{mex}\lbrace 0, 1, 2, 3 \rbrace \\
       &= 4 \ (= 4 \times 0 + 4)
\end{align*}
$$

$$
\begin{align*}
  g(4) &= \text{mex}\lbrace g(0), g(1), g(2), g(3), g(1) \oplus g(3), g(2) \oplus g(2) \rbrace \\
       &= \text{mex}\lbrace 0, 1, 2, 4, 1 \oplus 4, 2 \oplus 2 \rbrace \\
       &= \text{mex}\lbrace 0, 1, 2, 4, 5, 0 \rbrace \\
       &= 3 \ (= 4 \times 0 + 3)
\end{align*}
$$

よって、 $k = 0$ の場合成立する。

### (ⅱ) $k = 0, 1, ... , n$ で命題が成立すると仮定する。 $k = n+1$ の場合

#### $g(4k+1)$

- 攻撃遷移は、仮定より $\lbrace g(v) | 0 \leq v \leq 4k \rbrace = \lbrace 0, 1, 2, 4, 3, ... , 4k \rbrace$ の状態に到達可能である。
- 分裂遷移の遷移先は $g(1) \oplus g(4k), g(2) \oplus g(4k-1), ... , g(4k) \oplus g(1)$ と表せるが、過程よりこれらは全て以下のいずれかのパターンで表せる ($s, t$ は非負整数)

  - $g(4s + 1) \oplus g(4t + 4) = (4s + 1) \oplus (4t + 3) \equiv 2 \pmod 4$
  - $g(4s + 2) \oplus g(4t + 3) = (4s + 2) \oplus (4t + 4) \equiv 2 \pmod 4$
  - $g(4s + 3) \oplus g(4t + 2) = (4s + 4) \oplus (4t + 2) \equiv 2 \pmod 4$
  - $g(4s + 4) \oplus g(4t + 1) = (4s + 3) \oplus (4t + 1) \equiv 2 \pmod 4$

  よって、分裂の遷移で $4k + 1$ に到達することはない。

- したがって、 $\lbrace 0, 1, 2, 4, 3, ... , 4k, 4k \rbrace$ には到達できるが、 $4k + 1$ には到達できないため、 $g(4k + 1) = 4k + 1$ が成立する。

#### $g(4k+2)$

- 攻撃遷移は、仮定より $\lbrace g(v) | 0 \leq v \leq 4k + 1 \rbrace = \lbrace 0, 1, 2, 4, 3, ... , 4k, 4k + 1 \rbrace$ の状態に到達可能である。
- 分裂遷移の遷移先は $g(1) \oplus g(4k + 1), g(2) \oplus g(4k), ... , g(4k + 1) \oplus g(1)$ と表せるが、過程よりこれらは全て以下のいずれかのパターンで表せる ($s, t$ は非負整数)

  - $g(4s + 1) \oplus g(4t + 1) = (4s + 1) \oplus (4t + 1) \equiv 0 \pmod 4$
  - $g(4s + 2) \oplus g(4t + 4) = (4s + 2) \oplus (4t + 3) \equiv 3 \pmod 4$
  - $g(4s + 3) \oplus g(4t + 3) = (4s + 4) \oplus (4t + 4) \equiv 0 \pmod 4$
  - $g(4s + 4) \oplus g(4t + 2) = (4s + 3) \oplus (4t + 2) \equiv 3 \pmod 4$

  よって、分裂の遷移で $4k + 2$ に到達することはない。

- したがって、 $\lbrace 0, 1, 2, 4, 3, ... , 4k, 4k + 1 \rbrace$ には到達できるが、 $4k + 2$ には到達できないため、 $g(4k + 2) = 4k + 2$ が成立する。

#### $g(4k+3)$

- 攻撃遷移は、仮定より $\lbrace g(v) | 0 \leq v \leq 4k + 2 \rbrace = \lbrace 0, 1, 2, 4, 3, ... , 4k, 4k + 1, 4k + 2 \rbrace$ の状態に到達可能である。
- 分裂遷移の遷移先は $g(1) \oplus g(4k + 2), g(2) \oplus g(4k + 1), ... , g(4k + 2) \oplus g(1)$ と表せるが、過程よりこれらは全て以下のいずれかのパターンで表せる ($s, t$ は非負整数)

  - $g(4s + 1) \oplus g(4t + 2) = (4s + 1) \oplus (4t + 2) \equiv 3 \pmod 4$
  - $g(4s + 2) \oplus g(4t + 1) = (4s + 2) \oplus (4t + 1) \equiv 3 \pmod 4$
  - $g(4s + 3) \oplus g(4t + 4) = (4s + 4) \oplus (4t + 3) \equiv 3 \pmod 4$
  - $g(4s + 4) \oplus g(4t + 3) = (4s + 3) \oplus (4t + 4) \equiv 3 \pmod 4$

  $g(1) \oplus g(4k + 2) = 1 \oplus (4k + 2) = 4k + 3$ なので、分裂の遷移で $4k + 3$ に到達することは可能。
  ただし、分裂の遷移で $4k + 4$ に到達することは不可能。

- したがって、 $\lbrace 0, 1, 2, 4, 3, ... , 4k, 4k + 1, 4k + 2, 4k + 3 \rbrace$ には到達できるが、 $4k + 4$ には到達できないため、 $g(4k + 3) = 4k + 4$ が成立する。

<!-- **g(4k+4)** :
4k+3 未満は攻撃遷移で到達可能。分裂遷移の遷移先は g(4s+1) XOR g(4t+3), g(4s+2) XOR g(4t+2), g(4s+3) XOR g(4t+1), g(4s) XOR g(4t) で、これらは全て mod 4 で 3 にならない。よって g(4k+4) = 4k+3 -->

#### $g(4k+4)$

- 攻撃遷移は、仮定より $\lbrace g(v) | 0 \leq v \leq 4k + 3 \rbrace = \lbrace 0, 1, 2, 4, 3, ... , 4k, 4k + 1, 4k + 2, 4k + 4 \rbrace$ の状態に到達可能である。
- 分裂遷移の遷移先は $g(1) \oplus g(4k + 3), g(2) \oplus g(4k + 2), ... , g(4k + 3) \oplus g(1)$ と表せるが、過程よりこれらは全て以下のいずれかのパターンで表せる ($s, t$ は非負整数)

  - $g(4s + 1) \oplus g(4t + 3) = (4s + 1) \oplus (4t + 4) \equiv 1 \pmod 4$
  - $g(4s + 2) \oplus g(4t + 2) = (4s + 2) \oplus (4t + 2) \equiv 0 \pmod 4$
  - $g(4s + 3) \oplus g(4t + 1) = (4s + 4) \oplus (4t + 1) \equiv 1 \pmod 4$
  - $g(4s + 4) \oplus g(4t + 4) = (4s + 3) \oplus (4t + 3) \equiv 0 \pmod 4$

  よって、分裂の遷移で $4k + 3$ に到達することは不可能。

- したがって、 $\lbrace 0, 1, 2, 4, 3, ... , 4k, 4k + 1, 4k + 2, 4k + 4 \rbrace$ には到達できるが、 $4k + 3$ には到達できないため、 $g(4k + 4) = 4k + 3$ が成立する。

したがって、 $k = 0, 1, ... , n$ で命題が成立すると仮定すると、 $k = n+1$ の場合も命題が成立する。

以上、(ⅰ), (ⅱ) より、命題が成立する。

## 2. の証明

先頭 $D + D % 2$ 項目まで 1 に従うことを示す。

スライムの体力を $d$ として、 $1 \leq d \leq D$ の場合は、攻撃の遷移で $d$ 未満の全ての状態に遷移出来るので、 1 (ⅱ) の議論と同様にして 1 に従うことが示せる。

よって以下では $D + 1$ 以降について議論をする。

### (ⅰ) $D \equiv 0 \pmod 2$ の場合

- スライムの体力が $D + 1$ の場合、攻撃遷移で到達可能な $g(1) ~ g(D)$ に $0$ が存在しないため、分裂遷移で $0$ に到達可能かを考える。（到達不可能なら $\text{mex}\lbrace g(1), g(2), ... , g(D) \rbrace = 0$ となる）

- $x \oplus y = 0$ となるには、 $x = y$ が必要十分条件だが、 $D+1 ≡ 1 \pmod 2$ なので、分裂の遷移で到達する状態の Grundy 数は $g(2s) \oplus g(ts+1) \neq 0$ ($s, t$ は非負整数) となるため、 $0$ に到達不可能。

よって、 $g(D+1) = 0$ で $D+1$ 項目は $1$ に従わない。

### (ⅱ) $D \equiv 1 \pmod 2$ の場合

- スライムの体力が $D + 1$ の場合、攻撃遷移で到達可能な $g(1) ~ g(D)$ に $0$ が存在しないため、分裂遷移で $0$ に到達可能かを考える。（到達不可能なら $\text{mex}\lbrace g(1), g(2), ... , g(D) \rbrace = 0$ となる）

- D+1 ≡ 0 \pmod 2 なので、 $g((D + 1)/2) \oplus g((D + 1)/2) = 0$ といった遷移が存在し、分裂の遷移で 0 に到達可能。

- スライムの体力が $D + 2$ の場合、攻撃遷移で到達可能な $g(2) ~ g(D+1)$ に $0$ が存在しないため、分裂遷移で $0$ に到達可能かを考える。（到達不可能なら $\text{mex}\lbrace g(2), g(3), ... , g(D+1) \rbrace = 0$ となる）

- $x \oplus y = 0$ となるには、 $x = y$ が必要十分条件だが、 $D+2 ≡ 1 \pmod 2$ なので、分裂の遷移で到達する状態の Grundy 数は $g(2s) \oplus g(ts+1) \neq 0$ ($s, t$ は非負整数) となるため、 $0$ に到達不可能。

よって、 $g(D + 2) = 0$ で $D + 2$ 項目は 1 に従わない。

以上より、先頭 $D + D \ \% \ 2$ 項目まで 1 に従うことが示された。

## 3. の証明

以降 $D + D \ \% \ 2 = X$ とおく。以下が成立することを示す ※ $s, t$ は非負整数

### (Ⅰ) $D \equiv 0 \pmod 2$ の場合

- $g(X(t+1) + 1) = 0$
- $g(X(t+1) + 2) = D+1$
- $g(X(t+1) + 2 + 4s+1)=4s+1$
- $g(X(t+1) + 2 + 4s+2)=4s+2$
- $g(X(t+1) + 2 + 4s+3)=4s+4$
- $g(X(t+1) + 2 + 4s+4)=4s+3$
- s に関連する項は $D$ 項分だけ従う

### (Ⅱ) $D \equiv 1 \pmod 2$ の場合

- $g(X(t+1) + 1) = 0$
- $g(X(t+1) + 1 + 4s+1)=4s+2$
- $g(X(t+1) + 1 + 4s+2)=4s+1$
- $g(X(t+1) + 1 + 4s+3)=4s+3$
- $g(X(t+1) + 1 + 4s+4)=4s+4$
- s に関連する項は $D$ 項分だけ従う

(Ⅰ), (Ⅱ) はそれぞれ以下の順に行う。

(1) $t = 0$ として $\bmod 4$ で $s$ の周期の証明\
(2) $t = n$ が成立すると仮定した時の $t = n + 1$ として $\bmod 4$ で $s$ の周期の証明

<br>

#### (Ⅰ) (1)

- $g(X+1) = 0$ は 2 で証明済み。
- $g(X+2) = D+1$ は 2 で証明済み。
- $g(X+2 + 4s+1)=4s+2$, $g(X+2 + 4s+2)=4s+1$, $g(X+2 + 4s+3)=4s+3$, $g(X+2 + 4s+4)=4s+4$ は 1 (ⅱ) のように $s$ に関する帰納法で証明する。

(壱) $s = 0$ の場合

- $g(X + 2 + 1) = g(D + 3)$

  - $D \equiv 0 \pmod 2$ は $D \equiv 0 \pmod 4$ もしくは $D \equiv 2 \pmod 4$ である。先に $D \equiv 0 \pmod 4$ の場合を考える。

    - 攻撃遷移で到達可能な状態は $\lbrace 4, 3, 5, 6, ... , D, D - 1, 0, D + 1 \rbrace$ であり、 $1$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+2), g(2) \oplus g(D+1), ... , g(D+2) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - $g(1) \oplus g(D+2) = 1 \oplus (D+1) = D$
      - $g(2) \oplus g(D+1) = 2 \oplus 0 = 2$
      - $g(4x + 3) \oplus g(4y + 4) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
      - $g(4x + 4) \oplus g(4y + 3) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$
      - $g(4x + 1) \oplus g(4y + 2) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
      - $g(4x + 2) \oplus g(4y + 1) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$

    - $D \equiv 0 \pmod 2$ なので、 $0$ には到達できるが、 $1$ には到達できないので、 $g(D + 3) = 1 ( = 4 \times 0 + 1)$

  - 続いて $D \equiv 2 \pmod 4$ の場合について考える

    - 攻撃遷移で到達可能な状態は $\lbrace 4, 3, 5, 6, ... , D - 1, D, 0, D + 1 \rbrace$ であり、 $1$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+2), g(2) \oplus g(D+1), ... , g(D+2) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - $g(1) \oplus g(D+2) = 1 \oplus (D+1) = D$
      - $g(2) \oplus g(D+1) = 2 \oplus 0 = 2$
      - $g(4x + 3) \oplus g(4y + 2) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
      - $g(4x + 4) \oplus g(4y + 3) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$
      - $g(4x + 1) \oplus g(4y + 4) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
      - $g(4x + 2) \oplus g(4y + 1) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$

    - $D \equiv 2 \pmod 4$ なので、 $0$ には到達できるが、 $1$ には到達できないので、 $g(D + 3) = 1 ( = 4 \times 0 + 1)$

  - よって、 $g(X + 2 + 1) = 1$ が成立する。

- $g(X + 2 + 2) = g(D + 4)$

  - $D \equiv 0 \pmod 2$ は $D \equiv 0 \pmod 4$ もしくは $D \equiv 2 \pmod 4$ である。先に $D \equiv 0 \pmod 4$ の場合を考える。

    - 攻撃遷移で到達可能な状態は $\lbrace 3, 5, 6, ... , D, D - 1, 0, D + 1, 1 \rbrace$ であり、 $2$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+3), g(2) \oplus g(D+2), ... , g(D+3) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - $g(1) \oplus g(D+3) = 1 \oplus 1 = 0$
      - $g(2) \oplus g(D+2) = 2 \oplus (D+1) \equiv 1 \pmod 2$
      - $g(3) \oplus g(D+1) = 4 \oplus 0 \equiv 0 \pmod 4$
      - $g(4x + 4) \oplus g(4y + 4) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
      - $g(4x + 1) \oplus g(4y + 3) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$
      - $g(4x + 2) \oplus g(4y + 2) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
      - $g(4x + 3) \oplus g(4y + 1) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$

    - $D \equiv 0 \pmod 2$ なので、 $g(\lfloor (D-1) / 2 \rfloor) \oplus g(\lfloor (D-1) / 2 \rfloor + 1) = 1$ が言えるため、分裂の遷移で $1$ に到達可能。

    - したがって、 $0, 1$ には到達できるが、 $2$ には到達できないので、 $g(D + 3) = 2 ( = 4 \times 0 + 2)$

  - 続いて $D \equiv 2 \pmod 4$ の場合について考える

    - 攻撃遷移で到達可能な状態は $\lbrace 3, 5, 6, ... , D - 1, D, 0, D + 1, 1 \rbrace$ であり、 $2$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+3), g(2) \oplus g(D+2), ... , g(D+3) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - $g(1) \oplus g(D+3) = 1 \oplus 1 = 0$
      - $g(2) \oplus g(D+2) = 2 \oplus (D+1) \equiv 1 \pmod 2$
      - $g(3) \oplus g(D+1) = 4 \oplus 0 \equiv 0 \pmod 4$
      - $g(4x + 4) \oplus g(4y + 2) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
      - $g(4x + 1) \oplus g(4y + 1) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$
      - $g(4x + 2) \oplus g(4y + 4) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
      - $g(4x + 3) \oplus g(4y + 3) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$

    - $D \equiv 0 \pmod 2$ なので、 $g(\lfloor (D-1) / 2 \rfloor) \oplus g(\lfloor (D-1) / 2 \rfloor + 1) = 1$ が言えるため、分裂の遷移で $1$ に到達可能。

    - したがって、 $0, 1$ には到達できるが、 $2$ には到達できないので、 $g(D + 3) = 2 ( = 4 \times 0 + 2)$

  - よって、 $g(X + 2 + 2) = 2$ が成立する。

- $g(X + 2 + 3) = g(D + 5)$

  - $D \equiv 0 \pmod 2$ は $D \equiv 0 \pmod 4$ もしくは $D \equiv 2 \pmod 4$ である。先に $D \equiv 0 \pmod 4$ の場合を考える。

    - 攻撃遷移で到達可能な状態は $\lbrace 5, 6, ... , D - 1, D, 0, D + 1, 1, 2 \rbrace$ であり、 $4$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+4), g(2) \oplus g(D+3), ... , g(D+5) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - $g(1) \oplus g(D+4) = 1 \oplus 2 = 3$
      - $g(2) \oplus g(D+3) = 2 \oplus 1 = 3$
      - $g(3) \oplus g(D+2) = 4 \oplus (D+1) \equiv 1 \pmod 4$
      - $g(4) \oplus g(D+1) = 3 \oplus 0 \equiv 3 \pmod 4$
      - $g(4x + 1) \oplus g(4y + 4) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
      - $g(4x + 2) \oplus g(4y + 3) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$
      - $g(4x + 3) \oplus g(4y + 2) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
      - $g(4x + 4) \oplus g(4y + 1) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$

    - $0, 1, 2, 3$ には到達できるが、 $4$ には到達できないので、 $g(D + 5) = 4 ( = 4 \times 0 + 4)$

  - 続いて $D \equiv 2 \pmod 4$ の場合について考える

    - 攻撃遷移で到達可能な状態は $\lbrace 5, 6, ... , D - 1, D, 0, D + 1, 1, 2 \rbrace$ であり、 $4$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+4), g(2) \oplus g(D+3), ... , g(D+5) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - $g(1) \oplus g(D+4) = 1 \oplus 2 = 3$
      - $g(2) \oplus g(D+3) = 2 \oplus 1 = 3$
      - $g(3) \oplus g(D+2) = 4 \oplus (D+1) \equiv 1 \pmod 4$
      - $g(4) \oplus g(D+1) = 3 \oplus 0 \equiv 3 \pmod 4$
      - $g(4x + 1) \oplus g(4y + 2) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
      - $g(4x + 2) \oplus g(4y + 3) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$
      - $g(4x + 3) \oplus g(4y + 4) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
      - $g(4x + 4) \oplus g(4y + 1) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$

    - $0, 1, 2, 3$ には到達できるが、 $4$ には到達できないので、 $g(D + 5) = 4 ( = 4 \times 0 + 4)$

  - よって、 $g(X + 2 + 3) = 4$ が成立する。

- $g(X + 2 + 4) = g(D + 6)$

  - $D \equiv 0 \pmod 2$ は $D \equiv 0 \pmod 4$ もしくは $D \equiv 2 \pmod 4$ である。先に $D \equiv 0 \pmod 4$ の場合を考える。

    - 攻撃遷移で到達可能な状態は $\lbrace 6, ... , D - 1, D, 0, D + 1, 1, 2, 4 \rbrace$ であり、 $3$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+5), g(2) \oplus g(D+4), ... , g(D+6) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - $g(1) \oplus g(D+5) = 1 \oplus 4 = 5$
      - $g(2) \oplus g(D+4) = 2 \oplus 2 = 0$
      - $g(3) \oplus g(D+3) = 4 \oplus 1 = 5$
      - $g(4) \oplus g(D+2) = 3 \oplus (D+1) \equiv 0 \pmod 2$
      - $g(5) \oplus g(D+1) = 5 \oplus 0 = 5$
      - $g(4x + 2) \oplus g(4y + 4) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
      - $g(4x + 3) \oplus g(4y + 3) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$
      - $g(4x + 4) \oplus g(4y + 2) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
      - $g(4x + 1) \oplus g(4y + 1) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$

    - $0, 1, 2$ には到達できるが、 $3$ には到達できないので、 $g(D + 6) = 3 ( = 4 \times 0 + 3)$

  - 続いて $D \equiv 2 \pmod 4$ の場合について考える

    - 攻撃遷移で到達可能な状態は $\lbrace 6, ... , D - 1, D, 0, D + 1, 1, 2, 4 \rbrace$ であり、 $4$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+5), g(2) \oplus g(D+4), ... , g(D+6) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - $g(1) \oplus g(D+5) = 1 \oplus 4 = 5$
      - $g(2) \oplus g(D+4) = 2 \oplus 2 = 0$
      - $g(3) \oplus g(D+3) = 4 \oplus 1 = 5$
      - $g(4) \oplus g(D+2) = 3 \oplus (D+1) \equiv 0 \pmod 2$
      - $g(5) \oplus g(D+1) = 5 \oplus 0 = 5$
      - $g(4x + 2) \oplus g(4y + 2) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
      - $g(4x + 3) \oplus g(4y + 1) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$
      - $g(4x + 4) \oplus g(4y + 4) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
      - $g(4x + 1) \oplus g(4y + 3) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$

    - $0, 1, 2$ には到達できるが、 $3$ には到達できないので、 $g(D + 6) = 3 ( = 4 \times 0 + 3)$

  - よって、 $g(X + 2 + 4) = 3$ が成立する。

以上より、命題が成立する。

(弐) $s = 0, 1, ... , n$ で命題が成立すると仮定する。 $s = n+1$ の場合

- 先頭 $X$ 項は 1 に従うので、 $\bmod 4$ の値が周期 4 で繰り返される。
- また、 $s = n+1$ の場合に考慮する 4 項も、 $s = 0, 1, ... , n$ と同様に $\bmod 4$ の値が周期 4 で繰り返される。

- したがって、下記が言える。(s = 0 のシチュエーションと同じことが言える)

  - $g(X + 2 + 4(n+1)+1) = g(X + 2 + 4n+1)$
  - $g(X + 2 + 4(n+1)+2) = g(X + 2 + 4n+2)$
  - $g(X + 2 + 4(n+1)+3) = g(X + 2 + 4n+3)$
  - $g(X + 2 + 4(n+1)+4) = g(X + 2 + 4n+4)$

- またこれは、先頭 $X$ 項の周期と同じであり、同様に考えるとこの s に関わる周期も $D + D \ \% \ 2$ 項であることが言える。

以上 (壱), (弐) より、命題が成立する。

#### (Ⅰ) (2)

同様に $t$ に関する帰納法で証明する。

(壱) $t = 0$ の場合は (Ⅰ) (1) で証明済み。

(弐) $t = n$ で命題が成立すると仮定する。 $t = n+1$ の場合

- (Ⅰ) (1) より、先頭 $X$ 項とそれ以降の $s$ に関わる一般項が同じ周期であることが言えるため、下記の様にシチュエーションが同じとなる。

  - $g(Xn + 1) = g(X(n+1) + 1)$
  - $g(Xn + 2) = g(X(n+1) + 2)$
  - $g(Xn + 2 + 4s+1) = g(X(n) + 2 + 4s+1)$
  - $g(Xn + 2 + 4s+2) = g(X(n) + 2 + 4s+2)$
  - $g(Xn + 2 + 4s+3) = g(X(n) + 2 + 4s+3)$
  - $g(Xn + 2 + 4s+4) = g(X(n) + 2 + 4s+4)$
  - s に関連する項は $D$ 項分だけ従う

- したがって、 $t = n+1$ の場合も命題が成立する。

以上より、(Ⅰ) (1), (Ⅰ) (2) が成立するため、(Ⅰ) が成立する。

#### (Ⅱ) (1)

- $g(X+1) = 0$ は 2 で証明済み。
- $g(X+1 + 4s+1)=4s+2$, $g(X+1 + 4s+2)=4s+1$, $g(X+1 + 4s+3)=4s+3$, $g(X+1 + 4s+4)=4s+4$ は 1 (ⅱ) のように $s$ に関する帰納法で証明する。

(壱) $s = 0$ の場合

- $g(X + 1 + 1) = g(D + 3)$

  - $D \equiv 1 \pmod 2$ は $D \equiv 1 \pmod 4$ もしくは $D \equiv 3 \pmod 4$ である。先に $D \equiv 1 \pmod 4$ の場合を考える。

    - 攻撃遷移で到達可能な状態は $\lbrace 4, 3, 5, 6 ... , D - 1, 0 \rbrace$ であり、 $2$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+1), g(2) \oplus g(D), ... , g(D+1) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - $g(1) \oplus g(D+1) = 1 \oplus 0 = 1$
      - $g(4x + 2) \oplus g(4y + 2) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
      - $g(4x + 3) \oplus g(4y + 1) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$
      - $g(4x + 4) \oplus g(4y + 4) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
      - $g(4x + 1) \oplus g(4y + 3) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$

    - $0, 1$ には到達できるが、 $2$ には到達できないので、 $g(D + 2) = 2 ( = 4 \times 0 + 2)$

  - 続いて $D \equiv 3 \pmod 4$ の場合について考える

    - 攻撃遷移で到達可能な状態は $\lbrace 4, 3, 5, 6 ... , D - 1, 0 \rbrace$ であり、 $2$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+1), g(2) \oplus g(D), ... , g(D+1) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

    - $g(1) \oplus g(D+1) = 1 \oplus 0 = 1$
    - $g(4x + 2) \oplus g(4y + 4) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
    - $g(4x + 3) \oplus g(4y + 3) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$
    - $g(4x + 4) \oplus g(4y + 2) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
    - $g(4x + 1) \oplus g(4y + 1) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$

    - $0, 1$ には到達できるが、 $2$ には到達できないので、 $g(D + 2) = 2 ( = 4 \times 0 + 2)$

  - よって、 $g(X + 1 + 1) = 2$ が成立する。

- $g(X + 1 + 2) = g(D + 4)$

  - $D \equiv 1 \pmod 2$ は $D \equiv 1 \pmod 4$ もしくは $D \equiv 3 \pmod 4$ である。先に $D \equiv 1 \pmod 4$ の場合を考える。

    - 攻撃遷移で到達可能な状態は $\lbrace 3, 5, 6 ... , D - 1, 0, 2 \rbrace$ であり、 $1$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+2), g(2) \oplus g(D+1), ... , g(D+2) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

    - $g(1) \oplus g(D+2) = 1 \oplus 2 = 3$
    - $g(2) \oplus g(D+1) = 2 \oplus 0 = 2$
    - $g(4x + 3) \oplus g(4y + 2) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
    - $g(4x + 4) \oplus g(4y + 1) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$
    - $g(4x + 1) \oplus g(4y + 4) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
    - $g(4x + 2) \oplus g(4y + 3) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$

    - $0$ には到達できるが、 $1$ には到達できないので、 $g(D + 3) = 1 ( = 4 \times 0 + 1)$

  - 続いて $D \equiv 3 \pmod 4$ の場合について考える

    - 攻撃遷移で到達可能な状態は $\lbrace 3, 5, 6 ... , D - 1, 0, 2 \rbrace$ であり、 $1$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+2), g(2) \oplus g(D+1), ... , g(D+2) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

    - $g(1) \oplus g(D+2) = 1 \oplus 2 = 3$
    - $g(2) \oplus g(D+1) = 2 \oplus 0 = 2$
    - $g(4x + 3) \oplus g(4y + 4) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
    - $g(4x + 4) \oplus g(4y + 3) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$
    - $g(4x + 1) \oplus g(4y + 2) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
    - $g(4x + 2) \oplus g(4y + 1) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$

    - $0$ には到達できるが、 $1$ には到達できないので、 $g(D + 3) = 1 ( = 4 \times 0 + 1)$

  - よって、 $g(X + 1 + 2) = 1$ が成立する。

- $g(X + 1 + 3) = g(D + 5)$

  - $D \equiv 1 \pmod 2$ は $D \equiv 1 \pmod 4$ もしくは $D \equiv 3 \pmod 4$ である。先に $D \equiv 1 \pmod 4$ の場合を考える。

    - 攻撃遷移で到達可能な状態は $\lbrace 5, 6 ... , D - 1, 0, 2, 1 \rbrace$ であり、 $3$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+3), g(2) \oplus g(D+2), ... , g(D+3) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

    - $g(1) \oplus g(D+3) = 1 \oplus 1 = 0$
    - $g(2) \oplus g(D+2) = 2 \oplus 2 = 0$
    - $g(3) \oplus g(D+1) = 4 \oplus 0 = 4$
    - $g(4x + 4) \oplus g(4y + 2) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
    - $g(4x + 1) \oplus g(4y + 1) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$
    - $g(4x + 2) \oplus g(4y + 4) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
    - $g(4x + 3) \oplus g(4y + 3) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$

    - $0, 1, 2$ には到達できるが、 $3$ には到達できないので、 $g(D + 4) = 3 ( = 4 \times 0 + 3)$

  - 続いて $D \equiv 3 \pmod 4$ の場合について考える

    - 攻撃遷移で到達可能な状態は $\lbrace 5, 6 ... , D - 1, 0, 2, 1 \rbrace$ であり、 $3$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+3), g(2) \oplus g(D+2), ... , g(D+3) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

    - $g(1) \oplus g(D+3) = 1 \oplus 1 = 0$
    - $g(2) \oplus g(D+2) = 2 \oplus 2 = 0$
    - $g(3) \oplus g(D+1) = 4 \oplus 0 = 4$
    - $g(4x + 4) \oplus g(4y + 4) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
    - $g(4x + 1) \oplus g(4y + 3) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$
    - $g(4x + 2) \oplus g(4y + 2) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
    - $g(4x + 3) \oplus g(4y + 1) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$

    - $0, 1, 2$ には到達できるが、 $3$ には到達できないので、 $g(D + 4) = 3 ( = 4 \times 0 + 3)$

  - よって、 $g(X + 1 + 3) = 3$ が成立する。

- $g(X + 1 + 4) = g(D + 6)$

  - $D \equiv 1 \pmod 2$ は $D \equiv 1 \pmod 4$ もしくは $D \equiv 3 \pmod 4$ である。先に $D \equiv 1 \pmod 4$ の場合を考える。

    - 攻撃遷移で到達可能な状態は $\lbrace 6 ... , D - 1, 0, 2, 1, 3 \rbrace$ であり、 $4$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+4), g(2) \oplus g(D+3), ... , g(D+4) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

    - $g(1) \oplus g(D+4) = 1 \oplus 3 = 2$
    - $g(2) \oplus g(D+3) = 2 \oplus 1 = 3$
    - $g(3) \oplus g(D+2) = 4 \oplus 2 \equiv 2 \pmod 4$
    - $g(4) \oplus g(D+1) = 3 \oplus 0 = 3$
    - $g(4x + 1) \oplus g(4y + 2) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
    - $g(4x + 2) \oplus g(4y + 1) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$
    - $g(4x + 3) \oplus g(4y + 4) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
    - $g(4x + 4) \oplus g(4y + 3) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$

    - $0, 1, 2, 3$ には到達できるが、 $4$ には到達できないので、 $g(D + 5) = 4 ( = 4 \times 0 + 4)$

  - 続いて $D \equiv 3 \pmod 4$ の場合について考える

    - 攻撃遷移で到達可能な状態は $\lbrace 6 ... , D - 1, 0, 2, 1, 3 \rbrace$ であり、 $4$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g(D+4), g(2) \oplus g(D+3), ... , g(D+4) \oplus g(1)$ と表せるが、これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

    - $g(1) \oplus g(D+4) = 1 \oplus 3 = 2$
    - $g(2) \oplus g(D+3) = 2 \oplus 1 = 3$
    - $g(3) \oplus g(D+2) = 4 \oplus 2 \equiv 2 \pmod 4$
    - $g(4) \oplus g(D+1) = 3 \oplus 0 = 3$
    - $g(4x + 1) \oplus g(4y + 4) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
    - $g(4x + 2) \oplus g(4y + 3) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$
    - $g(4x + 3) \oplus g(4y + 2) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
    - $g(4x + 4) \oplus g(4y + 1) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$

    - $0, 1, 2, 3$ には到達できるが、 $4$ には到達できないので、 $g(D + 5) = 4 ( = 4 \times 0 + 4)$

  - よって、 $g(X + 1 + 4) = 4$ が成立する。

- ここで、 $g(X + 1 + D + 1)$ を考える。
- これは、 $g(X + 1) = 0$ に攻撃遷移で到達できない最小の状態である。
- ここで、 $X + 1 + D + 1 \equiv 1 \pmod 2$ であるため、分裂遷移で $0$ に到達することが不可能である。
- したがって、 $s$ に関連する項が $D$ 項分だけ従うことも成立する。

#### (Ⅱ) (2)

同様に $t$ に関する帰納法で証明する。

(壱) $t = 0$ の場合は (Ⅱ) (1) で証明済み。

(弐) $t = 0, 1, ... , n$ で命題が成立すると仮定する。 $t = n+1$ の場合

- $g(X(n+1) + 1) = g((D+1)(n+1) + 1)$

  - 攻撃遷移で到達可能な状態を考えると、直近 $D$ 項が $t = n$ の周期に従うため、 $0$ に到達できない。
  - また、 $(D+1)(n+1) + 1 \equiv 1 \pmod 2$ であるため、分裂遷移でも $0$ に到達てきない。
  - したがって、 $g(X(n+1) + 1) = 0$

- $g(X(n+1) + 1 + 1) = g((D+1)(n+1) + 2)$

  - $D \equiv 1 \pmod 2$ は $D \equiv 1 \pmod 4$ もしくは $D \equiv 3 \pmod 4$ である。先に $D \equiv 1 \pmod 4$ の場合を考える。

    - 攻撃遷移で到達可能な状態は $\lbrace 1, 3, 4, 6, ... , D, 0 \rbrace$ であり、 $2$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g((D+1)(n+1) + 1), g(2) \oplus g((D+1)(n+1)), ... , g((D+1)(n+1) + 1) \oplus g(1)$ と表せるが、これらは (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) または、(先頭 $X$ 項以降の周期)　$\oplus$ (先頭 $X$ 項以降の周期) といえる。これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 1) \oplus 0 = (4x + 1) \oplus 0 \equiv 1 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 1) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 4) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 3) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 2) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$

      - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 1) \oplus g(4y + 1) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 4) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 3) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 2) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$

    - $0, 1$ には到達できるが、 $2$ には到達できないので、 $g((D+1)(n+1) + 2) = 2 ( = 4 \times 0 + 2)$

  - 続いて $D \equiv 3 \pmod 4$ の場合について考える

    - 攻撃遷移で到達可能な状態は $\lbrace 1, 3, 4, 6, ... , D, 0 \rbrace$ であり、 $2$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g((D+1)(n+1) + 1), g(2) \oplus g((D+1)(n+1)), ... , g((D+1)(n+1) + 1) \oplus g(1)$ と表せるが、これらは (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) または、(先頭 $X$ 項以降の周期)　$\oplus$ (先頭 $X$ 項以降の周期) といえる。これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 1) \oplus 0 = (4x + 1) \oplus 0 \equiv 1 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 3) = (4x + 2) \oplus (4y + 3) \equiv 3 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 2) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 1) = (4x + 3) \oplus (4y + 2) \equiv 3 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 4) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$

      - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 1) \oplus g(4y + 3) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 2) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 1) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 4) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$

    - $0, 1$ には到達できるが、 $2$ には到達できないので、 $g((D+1)(n+1) + 2) = 2 ( = 4 \times 0 + 2)$

  - よって、 $g(X(n+1) + 1 + 1) = 2$ が成立する。

- $g(X(n+1) + 1 + 2) = g((D+1)(n+1) + 3)$

  - $D \equiv 1 \pmod 2$ は $D \equiv 1 \pmod 4$ もしくは $D \equiv 3 \pmod 4$ である。先に $D \equiv 1 \pmod 4$ の場合を考える。

    - 攻撃遷移で到達可能な状態は $\lbrace 3, 4, 6, ... , D, 0, 2 \rbrace$ であり、 $1$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g((D+1)(n+1) + 2), g(2) \oplus g((D+1)(n+1) + 1), ... , g((D+1)(n+1) + 2) \oplus g(1)$ と表せるが、これらは (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) または、(先頭 $X$ 項以降の周期)　$\oplus$ (先頭 $X$ 項以降の周期) といえる。これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 2) \oplus 0 = (4x + 2) \oplus 0 \equiv 1 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 1) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 4) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 3) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 2) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$

      - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 2) \oplus g(4y + 1) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 4) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 3) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 2) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$

    - $0$ には到達できるが、 $1$ には到達できないので、 $g((D+1)(n+1) + 3) = 1 ( = 4 \times 0 + 1)$

  - 続いて $D \equiv 3 \pmod 4$ の場合について考える

    - 攻撃遷移で到達可能な状態は $\lbrace 3, 4, 6, ... , D, 0, 2 \rbrace$ であり、 $1$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g((D+1)(n+1) + 2), g(2) \oplus g((D+1)(n+1) + 1), ... , g((D+1)(n+1) + 2) \oplus g(1)$ と表せるが、これらは (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) または、(先頭 $X$ 項以降の周期)　$\oplus$ (先頭 $X$ 項以降の周期) といえる。これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 2) \oplus 0 = (4x + 2) \oplus 0 \equiv 1 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 3) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 2) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 1) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 4) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$

      - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 2) \oplus g(4y + 3) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 2) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 1) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 4) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$

    - $0$ には到達できるが、 $1$ には到達できないので、 $g((D+1)(n+1) + 3) = 1 ( = 4 \times 0 + 1)$

  - よって、 $g(X(n+1) + 1 + 2) = 1$ が成立する。

- $g(X(n+1) + 1 + 3) = g((D+1)(n+1) + 4)$

  - $D \equiv 1 \pmod 2$ は $D \equiv 1 \pmod 4$ もしくは $D \equiv 3 \pmod 4$ である。先に $D \equiv 1 \pmod 4$ の場合を考える。

    - 攻撃遷移で到達可能な状態は $\lbrace 4, 6, ... , D, 0, 2, 1 \rbrace$ であり、 $3$ に到達不可能。

    - 分裂遷移の遷移先は $g(1) \oplus g((D+1)(n+1) + 3), g(2) \oplus g((D+1)(n+1) + 2), ... , g((D+1)(n+1) + 1) \oplus g(1)$ と表せるが、これらは (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) または、(先頭 $X$ 項以降の周期)　$\oplus$ (先頭 $X$ 項以降の周期) といえる。これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 3) \oplus 0 = (4x + 4) \oplus 0 \equiv 0 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 1) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 4) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 3) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 2) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$

      - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 3) \oplus g(4y + 1) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 4) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 3) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 2) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$

    - $0, 1, 2$ には到達できるが、 $3$ には到達できないので、 $g((D+1)(n+1) + 4) = 3 ( = 4 \times 0 + 3)$

  - 続いて $D \equiv 3 \pmod 4$ の場合について考える

    - 攻撃遷移で到達可能な状態は $\lbrace 4, 6, ... , D, 0, 2, 1 \rbrace$ であり、 $3$ に到達不可能。
    - 分裂遷移の遷移先は $g(1) \oplus g((D+1)(n+1) + 2), g(2) \oplus g((D+1)(n+1) + 1), ... , g((D+1)(n+1) + 2) \oplus g(1)$ と表せるが、これらは (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) または、(先頭 $X$ 項以降の周期)　$\oplus$ (先頭 $X$ 項以降の周期) といえる。これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 3) \oplus 0 = (4x + 4) \oplus 0 \equiv 0 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 3) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 2) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 1) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 4) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$

      - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 3) \oplus g(4y + 3) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 2) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 1) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 4) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$

    - $0, 1, 2$ には到達できるが、 $3$ には到達できないので、 $g((D+1)(n+1) + 4) = 3 ( = 4 \times 0 + 3)$

  - よって、 $g(X(n+1) + 1 + 3) = 3$ が成立する。

- $g(X(n+1) + 1 + 4) = g((D+1)(n+1) + 5)$

  - $D \equiv 1 \pmod 2$ は $D \equiv 1 \pmod 4$ もしくは $D \equiv 3 \pmod 4$ である。先に $D \equiv 1 \pmod 4$ の場合を考える。

    - 攻撃遷移で到達可能な状態は $\lbrace 6, ... , D, 0, 2, 1, 3 \rbrace$ であり、 $4$ に到達不可能。

    - 分裂遷移の遷移先は $g(1) \oplus g((D+1)(n+1) + 4), g(2) \oplus g((D+1)(n+1) + 3), ... , g((D+1)(n+1) + 4) \oplus g(4)$ と表せるが、これらは (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) または、(先頭 $X$ 項以降の周期)　$\oplus$ (先頭 $X$ 項以降の周期) といえる。これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 4) \oplus 0 = (4x + 3) \oplus 0 \equiv 3 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 1) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 4) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 3) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 2) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$

      - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 4) \oplus g(4y + 1) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 4) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 3) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 2) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$

    - $0, 1, 2, 3$ には到達できるが、 $4$ には到達できないので、 $g((D+1)(n+1) + 5) = 4 ( = 4 \times 0 + 3)$

  - 続いて $D \equiv 3 \pmod 4$ の場合について考える

    - 攻撃遷移で到達可能な状態は $\lbrace 6, ... , D, 0, 2, 1, 3 \rbrace$ であり、 $4$ に到達不可能。

    - 分裂遷移の遷移先は $g(1) \oplus g((D+1)(n+1) + 4), g(2) \oplus g((D+1)(n+1) + 3), ... , g((D+1)(n+1) + 4) \oplus g(4)$ と表せるが、これらは (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) または、(先頭 $X$ 項以降の周期)　$\oplus$ (先頭 $X$ 項以降の周期) といえる。これらは全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

      - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 4) \oplus 0 = (4x + 3) \oplus 0 \equiv 3 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 3) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 2) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 1) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 4) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$

      - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(4x + 4) \oplus g(4y + 3) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 2) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 1) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 4) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$

    - $0, 1, 2, 3$ には到達できるが、 $4$ には到達できないので、 $g((D+1)(n+1) + 5) = 4 ( = 4 \times 0 + 4)$

- 以上より、 $t = n + 1, s = 0$ の場合、命題は成り立つ。

- $s = 0, 1, ... , n$ が成り立つと仮定する。 $s = n + 1$ の場合を考える。

  - 先頭の周期も、それ以降の周期も $D + 1 (\equiv 0 \pmod 2)$ 項であるから、それ以降の周期を $n$ 回加えたとしても、有り得る御パターンは $s = 0$ と同じである。
  - よって $s = n + 1$ の場合も命題は成り立つ。

以上より、(Ⅱ) (1), (Ⅱ) (2) が成立するため、(Ⅱ) が成立する。

したがって、全ての命題が成立するので、Grundy 数の一般項は初めに述べた通りである。
