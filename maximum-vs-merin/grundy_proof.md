# Grundy 数の一般項の証明

以下、体力 H のスライムの Grundy 数を $g(H)$ と表現する。( $g(0) = 0, D$ は正の整数 ) \
三段階に分けて一般項を証明。

1. $D = \infty$ の場合 ($k$ は非負整数)

- $g(4k + 1) = 4k + 1$
- $g(4k + 2) = 4k + 2$
- $g(4k + 3) = 4k + 4$
- $g(4k + 4) = 4k + 3$

<br>

2. $D \neq \infty$ の場合に $g(0)$ を除いて先頭 $D + D \bmod 2$ 項目まで 1. に従う

<br>

3. 以降 $D + D \bmod 2 = X$ とおく。以下が成立することを示す ※ $s, t$ は正の整数

- $D \equiv 0 \pmod 2$ の場合 :

  - $g(Xt + 1) = 0$
  - $g(Xt + 2) = D + 1$
  - $g(Xt + 2 + 4s + 1)=4s + 1$
  - $g(Xt + 2 + 4s + 2)=4s + 2$
  - $g(Xt + 2 + 4s + 3)=4s + 4$
  - $g(Xt + 2 + 4s + 4)=4s + 3$
  - s に関連する項は $D$ 項分だけ従う

- $D \equiv 1 \pmod 2$ の場合
  - $g(Xt + 1) = 0$
  - $g(Xt + 1 + 4s + 1)=4s + 2$
  - $g(Xt + 1 + 4s + 2)=4s + 1$
  - $g(Xt + 1 + 4s + 3)=4s + 3$
  - $g(Xt + 1 + 4s + 4)=4s + 4$
  - s に関連する項は $D$ 項分だけ従う

<br>

## 1. の証明

$D = \infty$ の場合 ($k$ は非負整数)

- $g(4k + 1)=4k + 1$
- $g(4k + 2)=4k + 2$
- $g(4k + 3)=4k + 4$
- $g(4k + 4)=4k + 3$

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

### (ⅱ) $k = 0, 1, \cdots , n$ で命題が成立すると仮定する。 $k = n + 1$ の場合

- $g(4k + 1)$

- 攻撃遷移は、仮定より $\lbrace g(v) | 0 \leq v \leq 4k \rbrace = \lbrace 0, 1, 2, 4, 3, \cdots , 4k \rbrace$ の状態に到達可能である。
- 分裂遷移の遷移先は $g(1) \oplus g(4k), g(2) \oplus g(4k-1), \cdots , g(4k) \oplus g(1)$ と表せるが、仮定よりこれらは全て以下のいずれかのパターンで表せる ($s, t$ は非負整数)

  - $g(4s + 1) \oplus g(4t + 4) = (4s + 1) \oplus (4t + 3) \equiv 2 \pmod 4$
  - $g(4s + 2) \oplus g(4t + 3) = (4s + 2) \oplus (4t + 4) \equiv 2 \pmod 4$
  - $g(4s + 3) \oplus g(4t + 2) = (4s + 4) \oplus (4t + 2) \equiv 2 \pmod 4$
  - $g(4s + 4) \oplus g(4t + 1) = (4s + 3) \oplus (4t + 1) \equiv 2 \pmod 4$

  よって、分裂の遷移で $4k + 1$ に到達することはない。

- したがって、 $\lbrace 0, 1, 2, 4, 3, \cdots , 4k \rbrace$ には到達できるが、 $4k + 1$ には到達できないため、 $g(4k + 1) = 4k + 1$ が成立する。

- $g(4k + 2)$

  - 攻撃遷移は、仮定より $\lbrace g(v) | 0 \leq v \leq 4k + 1 \rbrace = \lbrace 0, 1, 2, 4, 3, \cdots , 4k, 4k + 1 \rbrace$ の状態に到達可能である。
  - 分裂遷移の遷移先は $g(1) \oplus g(4k + 1), g(2) \oplus g(4k), \cdots , g(4k + 1) \oplus g(1)$ と表せるが、仮定よりこれらは全て以下のいずれかのパターンで表せる ($s, t$ は非負整数)

    - $g(4s + 1) \oplus g(4t + 1) = (4s + 1) \oplus (4t + 1) \equiv 0 \pmod 4$
    - $g(4s + 2) \oplus g(4t + 4) = (4s + 2) \oplus (4t + 3) \equiv 3 \pmod 4$
    - $g(4s + 3) \oplus g(4t + 3) = (4s + 4) \oplus (4t + 4) \equiv 0 \pmod 4$
    - $g(4s + 4) \oplus g(4t + 2) = (4s + 3) \oplus (4t + 2) \equiv 3 \pmod 4$

    よって、分裂の遷移で $4k + 2$ に到達することはない。

  - したがって、 $\lbrace 0, 1, 2, 4, 3, \cdots , 4k, 4k + 1 \rbrace$ には到達できるが、 $4k + 2$ には到達できないため、 $g(4k + 2) = 4k + 2$ が成立する。

- $g(4k + 3)$

  - 攻撃遷移は、仮定より $\lbrace g(v) | 0 \leq v \leq 4k + 2 \rbrace = \lbrace 0, 1, 2, 4, 3, \cdots , 4k, 4k + 1, 4k + 2 \rbrace$ の状態に到達可能である。
  - 分裂遷移の遷移先は $g(1) \oplus g(4k + 2), g(2) \oplus g(4k + 1), \cdots , g(4k + 2) \oplus g(1)$ と表せるが、仮定よりこれらは全て以下のいずれかのパターンで表せる ($s, t$ は非負整数)

    - $g(4s + 1) \oplus g(4t + 2) = (4s + 1) \oplus (4t + 2) \equiv 3 \pmod 4$
    - $g(4s + 2) \oplus g(4t + 1) = (4s + 2) \oplus (4t + 1) \equiv 3 \pmod 4$
    - $g(4s + 3) \oplus g(4t + 4) = (4s + 4) \oplus (4t + 3) \equiv 3 \pmod 4$
    - $g(4s + 4) \oplus g(4t + 3) = (4s + 3) \oplus (4t + 4) \equiv 3 \pmod 4$

    $g(1) \oplus g(4k + 2) = 1 \oplus (4k + 2) = 4k + 3$ であるため、分裂の遷移で $4k + 3$ に到達することは可能。
    ただし、分裂の遷移で $4k + 4$ に到達することは不可能。

  - したがって、 $\lbrace 0, 1, 2, 4, 3, \cdots , 4k, 4k + 1, 4k + 2, 4k + 3 \rbrace$ には到達できるが、 $4k + 4$ には到達できないため、 $g(4k + 3) = 4k + 4$ が成立する。

- $g(4k + 4)$

  - 攻撃遷移は、仮定より $\lbrace g(v) | 0 \leq v \leq 4k + 3 \rbrace = \lbrace 0, 1, 2, 4, 3, \cdots , 4k, 4k + 1, 4k + 2, 4k + 4 \rbrace$ の状態に到達可能である。
  - 分裂遷移の遷移先は $g(1) \oplus g(4k + 3), g(2) \oplus g(4k + 2), \cdots , g(4k + 3) \oplus g(1)$ と表せるが、仮定よりこれらは全て以下のいずれかのパターンで表せる ($s, t$ は非負整数)

    - $g(4s + 1) \oplus g(4t + 3) = (4s + 1) \oplus (4t + 4) \equiv 1 \pmod 4$
    - $g(4s + 2) \oplus g(4t + 2) = (4s + 2) \oplus (4t + 2) \equiv 0 \pmod 4$
    - $g(4s + 3) \oplus g(4t + 1) = (4s + 4) \oplus (4t + 1) \equiv 1 \pmod 4$
    - $g(4s + 4) \oplus g(4t + 4) = (4s + 3) \oplus (4t + 3) \equiv 0 \pmod 4$

    よって、分裂の遷移で $4k + 3$ に到達することは不可能。

  - したがって、 $\lbrace 0, 1, 2, 4, 3, \cdots , 4k, 4k + 1, 4k + 2, 4k + 4 \rbrace$ には到達できるが、 $4k + 3$ には到達できないため、 $g(4k + 4) = 4k + 3$ が成立する。

  したがって、 $k = 0, 1, \cdots , n$ で命題が成立すると仮定すると、 $k = n + 1$ の場合も命題が成立する。

以上、(ⅰ), (ⅱ) より、命題が成立する。

## 2. の証明

先頭 $D + D \bmod 2$ 項目まで 1. に従うことを示す。

スライムの体力を $d$ として、 $1 \leq d \leq D$ の場合は、攻撃の遷移で $d$ 未満の全ての状態に遷移出来るので、 1 (ⅱ) の議論と同様にして 1. に従うことが示せる。

よって以下では $D + 1$ 以降について議論をする。

### (ⅰ) $D \equiv 0 \pmod 2$ の場合

- スライムの体力が $D + 1$ の場合、攻撃遷移で到達可能な $\lbrace g(k) | 1 \leq k \leq D, k は整数 \rbrace$ に $0$ が存在しないため、分裂遷移で $0$ に到達可能かを考える。

- $x \oplus y = 0$ となるには、 $x = y$ が必要十分条件だが、 $D + 1 ≡ 1 \pmod 2$ であるため、分裂の遷移で到達する状態の Grundy 数は $g(2s) \oplus g(2t + 1) \neq 0$ ($s, t$ は非負整数) となるため、 $0$ に到達不可能。

よって、 $g(D + 1) = 0$ で $D + 1$ 項目は 1. に従わない。

### (ⅱ) $D \equiv 1 \pmod 2$ の場合

- スライムの体力が $D + 1$ の場合、攻撃遷移で到達可能な $\lbrace g(k) | 1 \leq k \leq D, k は整数 \rbrace = \lbrace 1, 2, \cdots , D - 1, D \rbrace$ で、 $0$ が存在しないため、分裂遷移で $0$ に到達可能かを考える。

  - $D + 1 ≡ 0 \pmod 2$ であるため、 $g((D + 1)/2) \oplus g((D + 1)/2) = 0$ といった遷移が存在し、分裂の遷移で $0$ に到達可能。
  - $0$ 以外の到達可能かの議論は、1. と同様に議論することで $D + 1$ 項が 1. に従うことが示される。

- スライムの体力が $D + 2$ の場合、攻撃遷移で到達可能な $\lbrace g(k) | 1 \leq k \leq D + 1, k は整数 \rbrace$ に $0$ が存在しないため、分裂遷移で $0$ に到達可能かを考える。

  - $x \oplus y = 0$ となるには、 $x = y$ が必要十分条件だが、 $D + 2 ≡ 1 \pmod 2$ であるため、分裂の遷移で到達する状態の Grundy 数は $g(2s) \oplus g(2t + 1) \neq 0$ ($s, t$ は非負整数) となるため、 $0$ に到達不可能。

よって、 $g(D + 2) = 0$ で $D + 2$ 項目は 1. に従わない。

以上より、先頭 $D + D \bmod 2$ 項目まで 1. に従うことが示された。

## 3. の証明

以降 $D + D \bmod 2 = X$ とおく。以下が成立することを示す ※ $s, t$ は正の整数

(Ⅰ) $D \equiv 0 \pmod 2$ の場合

- $g(Xt + 1) = 0$
- $g(Xt + 2) = D + 1$
- $g(Xt + 2 + 4s + 1)=4s + 1$
- $g(Xt + 2 + 4s + 2)=4s + 2$
- $g(Xt + 2 + 4s + 3)=4s + 4$
- $g(Xt + 2 + 4s + 4)=4s + 3$
- s に関連する項は $D$ 項分だけ従う

(Ⅱ) $D \equiv 1 \pmod 2$ の場合

- $g(Xt + 1) = 0$
- $g(Xt + 1 + 4s + 1)=4s + 2$
- $g(Xt + 1 + 4s + 2)=4s + 1$
- $g(Xt + 1 + 4s + 3)=4s + 3$
- $g(Xt + 1 + 4s + 4)=4s + 4$
- s に関連する項は $D$ 項分だけ従う

<br>

### (Ⅰ)

- まず、 $D \equiv 0 \pmod 2$ の時の一般項は、先頭 $D$ 項と、2 周期目以降の $0, D + 1$ 以外の周期の項が一致するので、下記のような周期であるともとらえられる

  - $g(X(t - 1) + 4s + 1)=4s + 1$
  - $g(X(t - 1) + 4s + 2)=4s + 2$
  - $g(X(t - 1) + 4s + 3)=4s + 4$
  - $g(X(t - 1) + 4s + 4)=4s + 3$
  - $g(X(t - 1) + D + 1) = 0$
  - $g(X(t - 1) + D + 2) = D + 1$

- したがって、上記数列が成立することを示せば、元の数列も成立するので、上記数列を $t$ における数学的帰納法で証明する。

#### (壱) $t = 1$ の場合

- $g(1)$ から $g(D + 1)$ は 1. 2. で証明済み。

- $g(D + 2) = D + 1$

  - 攻撃遷移では、 $D \equiv 0 \pmod 4 の時は \lbrace 2, 4, 3, 5, \cdots , D, D - 1, 0 \rbrace$、 $D \equiv 2 \pmod 4 の時は \lbrace 2, 4, 3, 5, \cdots , D - 1, D, 0 \rbrace$、に到達可能。（$1$ 以外の要素に到達可能。）
  - $g(X + 1) \oplus g(1) = 0 \oplus 1 = 1$ のため、分裂遷移で $1$ に到達可能。
  - $D + 1$ に分裂遷移で到達可能かを下記の 4 パターンで議論する。

    - $D \equiv 0 \pmod 8$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(D + 1) = 1 \oplus 0 = 1$
        - $g(8x + 2) \oplus g(8y + 8) = (8x + 2) \oplus (8y + 7) \equiv 5 \pmod 8$
        - $g(8x + 3) \oplus g(8y + 7) = (8x + 4) \oplus (8y + 8) \equiv 4 \pmod 8$
        - $g(8x + 4) \oplus g(8y + 6) = (8x + 3) \oplus (8y + 6) \equiv 5 \pmod 8$
        - $g(8x + 5) \oplus g(8y + 5) = (8x + 5) \oplus (8y + 5) \equiv 0 \pmod 8$
        - $g(8x + 6) \oplus g(8y + 4) = (8x + 6) \oplus (8y + 3) \equiv 5 \pmod 8$
        - $g(8x + 7) \oplus g(8y + 3) = (8x + 8) \oplus (8y + 4) \equiv 4 \pmod 8$
        - $g(8x + 8) \oplus g(8y + 2) = (8x + 7) \oplus (8y + 2) \equiv 5 \pmod 8$
        - $g(8x + 1) \oplus g(8y + 1) = (8x + 1) \oplus (8y + 1) \equiv 0 \pmod 8$

      - $D + 1 \equiv 1 \pmod 8$ のため、 $0, 1, \cdots, D$ には到達できるが、 $D + 1$ には到達できない

    - $D \equiv 2 \pmod 8$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(X + 1) = 1 \oplus 0 = 1$
        - $g(8x + 2) \oplus g(8y + 2) = (8x + 2) \oplus (8y + 2) \equiv 0 \pmod 8$
        - $g(8x + 3) \oplus g(8y + 1) = (8x + 4) \oplus (8y + 1) \equiv 5 \pmod 8$
        - $g(8x + 4) \oplus g(8y + 8) = (8x + 3) \oplus (8y + 7) \equiv 4 \pmod 8$
        - $g(8x + 5) \oplus g(8y + 7) = (8x + 5) \oplus (8y + 8) \equiv 5 \pmod 8$
        - $g(8x + 6) \oplus g(8y + 6) = (8x + 6) \oplus (8y + 6) \equiv 0 \pmod 8$
        - $g(8x + 7) \oplus g(8y + 5) = (8x + 8) \oplus (8y + 5) \equiv 5 \pmod 8$
        - $g(8x + 8) \oplus g(8y + 4) = (8x + 7) \oplus (8y + 3) \equiv 4 \pmod 8$
        - $g(8x + 1) \oplus g(8y + 3) = (8x + 1) \oplus (8y + 4) \equiv 5 \pmod 8$

      - $D + 1 \equiv 3 \pmod 8$ のため、 $0, 1, \cdots, D$ には到達できるが、 $D + 1$ には到達できない

    - $D \equiv 4 \pmod 8$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(X + 1) = 1 \oplus 0 = 1$
        - $g(8x + 2) \oplus g(8y + 4) = (8x + 2) \oplus (8y + 3) \equiv 1 \pmod 8$
        - $g(8x + 3) \oplus g(8y + 3) = (8x + 4) \oplus (8y + 4) \equiv 0 \pmod 8$
        - $g(8x + 4) \oplus g(8y + 2) = (8x + 3) \oplus (8y + 2) \equiv 1 \pmod 8$
        - $g(8x + 5) \oplus g(8y + 1) = (8x + 5) \oplus (8y + 1) \equiv 4 \pmod 8$
        - $g(8x + 6) \oplus g(8y + 8) = (8x + 6) \oplus (8y + 7) \equiv 1 \pmod 8$
        - $g(8x + 7) \oplus g(8y + 7) = (8x + 8) \oplus (8y + 8) \equiv 0 \pmod 8$
        - $g(8x + 8) \oplus g(8y + 6) = (8x + 7) \oplus (8y + 6) \equiv 1 \pmod 8$
        - $g(8x + 1) \oplus g(8y + 5) = (8x + 1) \oplus (8y + 5) \equiv 4 \pmod 8$

      - $D + 1 \equiv 5 \pmod 8$ のため、 $0, 1, \cdots, D$ には到達できるが、 $D + 1$ には到達できない

    - $D \equiv 6 \pmod 8$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(X + 1) = 1 \oplus 0 = 1$
        - $g(8x + 2) \oplus g(8y + 6) = (8x + 2) \oplus (8y + 6) \equiv 4 \pmod 8$
        - $g(8x + 3) \oplus g(8y + 5) = (8x + 4) \oplus (8y + 5) \equiv 1 \pmod 8$
        - $g(8x + 4) \oplus g(8y + 4) = (8x + 3) \oplus (8y + 3) \equiv 0 \pmod 8$
        - $g(8x + 5) \oplus g(8y + 3) = (8x + 5) \oplus (8y + 4) \equiv 1 \pmod 8$
        - $g(8x + 6) \oplus g(8y + 2) = (8x + 6) \oplus (8y + 2) \equiv 4 \pmod 8$
        - $g(8x + 7) \oplus g(8y + 1) = (8x + 8) \oplus (8y + 1) \equiv 1 \pmod 8$
        - $g(8x + 8) \oplus g(8y + 8) = (8x + 7) \oplus (8y + 7) \equiv 0 \pmod 8$
        - $g(8x + 1) \oplus g(8y + 7) = (8x + 1) \oplus (8y + 8) \equiv 1 \pmod 8$

      - $D + 1 \equiv 7 \pmod 8$ のため、 $0, 1, \cdots, D$ には到達できるが、 $D + 1$ には到達できない

  - 以上より、 $g(D + 2) = D + 1$

したがって、 $t = 1$ の場合に命題が成立する。

#### (弐) $t = n$ の場合に命題が成立すると仮定する。 $t = n + 1$ の場合に命題が成立することを示す。

まず $s = 0$ の場合を考える。

- $g(X(n + 1) + 1) = 1$

  - 攻撃遷移で到達可能な状態は $\lbrace 4, 3, 5, 6, \cdots , 0, D + 1 \rbrace$ であり、 $1$ に到達不可能。
  - 分裂遷移で到達可能かを下記の 2 パターンで議論する。

    - $D \equiv 0 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w (z + w = n)$ は非負整数)

        - $g(Xz + 1) \oplus g(Xw + D + 2) = 1 \oplus (D + 1) \equiv 0 \pmod 4$
        - $g(Xz + 2) \oplus g(Xw + D + 1) = 2 \oplus 0 = 2$
        - $g(Xz + 4x + 3) \oplus g(Xw + 4y + 4) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
        - $g(Xz + 4x + 4) \oplus g(Xw + 4y + 3) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$
        - $g(Xz + 4x + 1) \oplus g(Xw + 4y + 2) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
        - $g(Xz + 4x + 2) \oplus g(Xw + 4y + 1) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$

      - $0$ には到達できるが、 $1$ には到達できない

    - $D \equiv 2 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w (z + w = n)$ は非負整数)

        - $g(1) \oplus g(D + 2) = 1 \oplus (D + 1) \equiv 2 \pmod 4$
        - $g(2) \oplus g(D + 1) = 2 \oplus 0 = 2$
        - $g(4x + 3) \oplus g(4y + 2) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 1) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 4) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 3) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$

      - $0$ には到達できるが、 $1$ には到達できない

  - よって、 $g(X(n + 1) + 1) = 1$ が成立する。

- $g(X(n + 1) + 2) = 2$

  - 攻撃遷移で到達可能な状態は $\lbrace 3, 5, 6, \cdots , 0, D + 1, 1 \rbrace$ であり、 $2$ に到達不可能。
  - 分裂遷移で到達可能かを下記の 2 パターンで議論する。

    - $D \equiv 0 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w (z + w = n)$ は非負整数)

        - $g(Xz + 2) \oplus g(Xw + D + 2) = 2 \oplus (D + 1) \equiv D + 3 \pmod 4$
        - $g(Xz + 3) \oplus g(Xw + D + 1) = 3 \oplus 0 = 3$
        - $g(Xz + 4x + 4) \oplus g(Xw + 4y + 4) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
        - $g(Xz + 4x + 1) \oplus g(Xw + 4y + 3) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$
        - $g(Xz + 4x + 2) \oplus g(Xw + 4y + 2) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
        - $g(Xz + 4x + 3) \oplus g(Xw + 4y + 1) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$

      - $0, 1$ には到達できるが、 $2$ には到達できない

    - $D \equiv 2 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w (z + w = n)$ は非負整数)

        - $g(Xz + 2) \oplus g(Xw + D + 2) = 2 \oplus (D + 1) \equiv D + 3 \pmod 4$
        - $g(Xz + 3) \oplus g(Xw + D + 1) = 4 \oplus 0 = 0$
        - $g(Xz + 4x + 4) \oplus g(Xw + 4y + 2) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
        - $g(Xz + 4x + 1) \oplus g(Xw + 4y + 1) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$
        - $g(Xz + 4x + 2) \oplus g(Xw + 4y + 4) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
        - $g(Xz + 4x + 3) \oplus g(Xw + 4y + 3) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$

      - $0, 1$ には到達できるが、 $2$ には到達できない

  - よって、 $g(X(n + 1) + 2) = 2$ が成立する。

- $g(X(n + 1) + 3) = 4$

  - 攻撃遷移で到達可能な状態は $\lbrace 5, 6, \cdots , 0, D + 1, 1, 2 \rbrace$ であり、 $4$ に到達不可能。
  - 分裂遷移で到達可能かを下記の 2 パターンで議論する。

    - $D \equiv 0 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w (z + w = n)$ は非負整数)

        - $g(Xz + 3) \oplus g(Xw + D + 2) = 4 \oplus (D + 1) \equiv 1 \pmod 4$
        - $g(Xz + 4) \oplus g(Xw + D + 1) = 3 \oplus 0 = 3$
        - $g(Xz + 4x + 1) \oplus g(Xw + 4y + 4) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
        - $g(Xz + 4x + 2) \oplus g(Xw + 4y + 3) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$
        - $g(Xz + 4x + 3) \oplus g(Xw + 4y + 2) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
        - $g(Xz + 4x + 4) \oplus g(Xw + 4y + 1) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$

      - $0, 1, 2, 3$ には到達できるが、 $4$ には到達できない

    - $D \equiv 2 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w (z + w = n)$ は非負整数)

        - $g(Xz + 3) \oplus g(Xw + D + 2) = 4 \oplus (D + 1) \equiv 3 \pmod 4$
        - $g(Xz + 4) \oplus g(Xw + D + 1) = 3 \oplus 0 = 3$
        - $g(Xz + 4x + 1) \oplus g(Xw + 4y + 2) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
        - $g(Xz + 4x + 2) \oplus g(Xw + 4y + 1) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$
        - $g(Xz + 4x + 3) \oplus g(Xw + 4y + 4) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
        - $g(Xz + 4x + 4) \oplus g(Xw + 4y + 3) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$

      - $0, 1, 2, 3$ には到達できるが、 $4$ には到達できない

  - よって、 $g(X(n + 1) + 3) = 4$ が成立する。

- $g(X(n + 1) + 4) = 3$

  - 攻撃遷移で到達可能な状態は $\lbrace 6, \cdots , 0, D + 1, 1, 2, 4 \rbrace$ であり、 $3$ に到達不可能。
  - 分裂遷移で到達可能かを下記の 2 パターンで議論する。

    - $D \equiv 0 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w (z + w = n)$ は非負整数)

        - $g(Xz + 4) \oplus g(Xw + D + 2) = 3 \oplus (D + 1) \equiv 2 \pmod 4$
        - $g(Xz + 5) \oplus g(Xw + D + 1) = 5 \oplus 0 = 5$
        - $g(Xz + 4x + 2) \oplus g(Xw + 4y + 4) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
        - $g(Xz + 4x + 3) \oplus g(Xw + 4y + 3) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$
        - $g(Xz + 4x + 4) \oplus g(Xw + 4y + 2) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
        - $g(Xz + 4x + 1) \oplus g(Xw + 4y + 1) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$

      - $0, 1, 2$ には到達できるが、 $3$ には到達できない

    - $D \equiv 2 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w (z + w = n)$ は非負整数)

        - $g(Xz + 4) \oplus g(Xw + D + 2) = 3 \oplus (D + 1) \equiv 2 \pmod 4$
        - $g(Xz + 5) \oplus g(Xw + D + 1) = 5 \oplus 0 = 5$
        - $g(Xz + 4x + 2) \oplus g(Xw + 4y + 2) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
        - $g(Xz + 4x + 3) \oplus g(Xw + 4y + 1) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$
        - $g(Xz + 4x + 4) \oplus g(Xw + 4y + 4) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
        - $g(Xz + 4x + 1) \oplus g(Xw + 4y + 3) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$

      - $0, 1, 2$ には到達できるが、 $3$ には到達できない

  - よって、 $g(X(n + 1) + 4) = 3$ が成立する。

したがって、 $s = 0$ の場合に命題が成立する。

ここで $s = n$ で命題が成立すると仮定する。 $s = n + 1$ の場合を考える。

- 仮定より、下記が言える。

  - $g(Xt + 1 + 4(n + 1) + 1) = g(Xt + 1 + 4n + 1) + 4$
  - $g(Xt + 1 + 4(n + 1) + 2) = g(Xt + 1 + 4n + 2) + 4$
  - $g(Xt + 1 + 4(n + 1) + 3) = g(Xt + 1 + 4n + 3) + 4$
  - $g(Xt + 1 + 4(n + 1) + 4) = g(Xt + 1 + 4n + 4) + 4$

したがって、 $s = n + 1$ も $s = n$ と同様に議論できることから、命題が成立する。

- $g(X(n + 1) + D + 1) = 0$

  - スライムの体力が $D + 1$ の場合、攻撃遷移で到達可能な $\lbrace g(k) | 1 \leq k \leq D, k は整数 \rbrace$ に $0$ が存在しないため、分裂遷移で $0$ に到達可能かを考える。

  - $x \oplus y = 0$ となるには、 $x = y$ が必要十分条件だが、 $D + 1 ≡ 1 \pmod 2$ であるため、分裂の遷移で到達する状態の Grundy 数は $g(2s) \oplus g(2t + 1) \neq 0$ ($s, t$ は非負整数) となるため、 $0$ に到達不可能。

  - したがって、 $g(D + 1) = 0$
  - これにより、 $s$ に関連する項が $D$ 項分だけ従うことも成立する。

- $g(X(n + 1) + D + 2) = D + 1$

  - 攻撃遷移では、 $D \equiv 0 \pmod 4 の時は \lbrace 2, 4, 3, 5, \cdots , D, D - 1, 0 \rbrace$、 $D \equiv 2 \pmod 4 の時は \lbrace 2, 4, 3, 5, \cdots , D - 1, D, 0 \rbrace$、に到達可能。（$1$ 以外の要素に到達可能。）
  - $g(X + 1) \oplus g(1) = 0 \oplus 1 = 1$ のため、分裂遷移で $1$ に到達可能。
  - $D + 1$ に分裂遷移で到達可能かを下記の 4 パターンで議論する。

    - $D \equiv 0 \pmod 8$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w (z + w = n - 1)$ は非負整数)

        - $g(Xz + 1) \oplus g(Xw + D + 1) = 1 \oplus 0 = 1$
        - $g(Xz + 8x + 2) \oplus g(Xw + 8y + 8) = (8x + 2) \oplus (8y + 7) \equiv 5 \pmod 8$
        - $g(Xz + 8x + 3) \oplus g(Xw + 8y + 7) = (8x + 4) \oplus (8y + 8) \equiv 4 \pmod 8$
        - $g(Xz + 8x + 4) \oplus g(Xw + 8y + 6) = (8x + 3) \oplus (8y + 6) \equiv 5 \pmod 8$
        - $g(Xz + 8x + 5) \oplus g(Xw + 8y + 5) = (8x + 5) \oplus (8y + 5) \equiv 0 \pmod 8$
        - $g(Xz + 8x + 6) \oplus g(Xw + 8y + 4) = (8x + 6) \oplus (8y + 3) \equiv 5 \pmod 8$
        - $g(Xz + 8x + 7) \oplus g(Xw + 8y + 3) = (8x + 8) \oplus (8y + 4) \equiv 4 \pmod 8$
        - $g(Xz + 8x + 8) \oplus g(Xw + 8y + 2) = (8x + 7) \oplus (8y + 2) \equiv 5 \pmod 8$
        - $g(Xz + 8x + 1) \oplus g(Xw + 8y + 1) = (8x + 1) \oplus (8y + 1) \equiv 0 \pmod 8$
        - $g(Xz + D) \oplus g(X(w - 1) + D + 2) = (D - 1) \oplus 0 = D - 1$

      - $D - 1 \equiv 7 \pmod 8$ のため、 $0, 1, \cdots, D$ には到達できるが、 $D + 1$ には到達できない

    - $D \equiv 2 \pmod 8$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(X + 1) = 1 \oplus 0 = 1$
        - $g(8x + 2) \oplus g(8y + 2) = (8x + 2) \oplus (8y + 2) \equiv 0 \pmod 8$
        - $g(8x + 3) \oplus g(8y + 1) = (8x + 4) \oplus (8y + 1) \equiv 5 \pmod 8$
        - $g(8x + 4) \oplus g(8y + 8) = (8x + 3) \oplus (8y + 7) \equiv 4 \pmod 8$
        - $g(8x + 5) \oplus g(8y + 7) = (8x + 5) \oplus (8y + 8) \equiv 5 \pmod 8$
        - $g(8x + 6) \oplus g(8y + 6) = (8x + 6) \oplus (8y + 6) \equiv 0 \pmod 8$
        - $g(8x + 7) \oplus g(8y + 5) = (8x + 8) \oplus (8y + 5) \equiv 5 \pmod 8$
        - $g(8x + 8) \oplus g(8y + 4) = (8x + 7) \oplus (8y + 3) \equiv 4 \pmod 8$
        - $g(8x + 1) \oplus g(8y + 3) = (8x + 1) \oplus (8y + 4) \equiv 5 \pmod 8$
        - $g(Xz + D) \oplus g(X(w - 1) + D + 2) = D \oplus 0 = D$

      - $D \equiv 2 \pmod 8$ のため、 $0, 1, \cdots, D$ には到達できるが、 $D + 1$ には到達できない

    - $D \equiv 4 \pmod 8$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(X + 1) = 1 \oplus 0 = 1$
        - $g(8x + 2) \oplus g(8y + 4) = (8x + 2) \oplus (8y + 3) \equiv 1 \pmod 8$
        - $g(8x + 3) \oplus g(8y + 3) = (8x + 4) \oplus (8y + 4) \equiv 0 \pmod 8$
        - $g(8x + 4) \oplus g(8y + 2) = (8x + 3) \oplus (8y + 2) \equiv 1 \pmod 8$
        - $g(8x + 5) \oplus g(8y + 1) = (8x + 5) \oplus (8y + 1) \equiv 4 \pmod 8$
        - $g(8x + 6) \oplus g(8y + 8) = (8x + 6) \oplus (8y + 7) \equiv 1 \pmod 8$
        - $g(8x + 7) \oplus g(8y + 7) = (8x + 8) \oplus (8y + 8) \equiv 0 \pmod 8$
        - $g(8x + 8) \oplus g(8y + 6) = (8x + 7) \oplus (8y + 6) \equiv 1 \pmod 8$
        - $g(8x + 1) \oplus g(8y + 5) = (8x + 1) \oplus (8y + 5) \equiv 4 \pmod 8$
        - $g(Xz + D) \oplus g(X(w - 1) + D + 2) = (D - 1) \oplus 0 = D - 1$

      - $D - 1 \equiv 3 \pmod 8$ のため、 $0, 1, \cdots, D$ には到達できるが、 $D + 1$ には到達できない

    - $D \equiv 6 \pmod 8$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(X + 1) = 1 \oplus 0 = 1$
        - $g(8x + 2) \oplus g(8y + 6) = (8x + 2) \oplus (8y + 6) \equiv 4 \pmod 8$
        - $g(8x + 3) \oplus g(8y + 5) = (8x + 4) \oplus (8y + 5) \equiv 1 \pmod 8$
        - $g(8x + 4) \oplus g(8y + 4) = (8x + 3) \oplus (8y + 3) \equiv 0 \pmod 8$
        - $g(8x + 5) \oplus g(8y + 3) = (8x + 5) \oplus (8y + 4) \equiv 1 \pmod 8$
        - $g(8x + 6) \oplus g(8y + 2) = (8x + 6) \oplus (8y + 2) \equiv 4 \pmod 8$
        - $g(8x + 7) \oplus g(8y + 1) = (8x + 8) \oplus (8y + 1) \equiv 1 \pmod 8$
        - $g(8x + 8) \oplus g(8y + 8) = (8x + 7) \oplus (8y + 7) \equiv 0 \pmod 8$
        - $g(8x + 1) \oplus g(8y + 7) = (8x + 1) \oplus (8y + 8) \equiv 1 \pmod 8$
        - $g(Xz + D) \oplus g(X(w - 1) + D + 2) = D \oplus 0 = D$

      - $D \equiv 6 \pmod 8$ のため、 $0, 1, \cdots, D$ には到達できるが、 $D + 1$ には到達できない

  - 以上より、 $g(D + 2) = D + 1$

したがって、 $t = n$ が成立すると仮定した場合に、 $t = n + 1$ でも命題が成立する。

以上 (壱) (弐) より、 $D \equiv 0 \pmod 2$ の時の Grundy 数の一般項が示せた。

### (Ⅱ)

#### (壱) $t = 1$ の場合

- $g(X + 1) = 0$ は 2. で証明済み。
- $g(X + 1 + 4s + 1)=4s + 2$, $g(X + 1 + 4s + 2)=4s + 1$, $g(X + 1 + 4s + 3)=4s + 3$, $g(X + 1 + 4s + 4)=4s + 4$ は 1 (ⅱ) のように $s$ に関する帰納法で証明する。

まず $s = 0$ の場合を考える。

- $g(X + 1 + 1) = g(D + 3)$

  - 攻撃遷移で到達可能な状態は $\lbrace 4, 3, 5, 6 \cdots , D - 1, 0 \rbrace$ であり、 $2$ に到達不可能。
  - 分裂遷移で到達可能かを下記の 2 パターンで議論する。

    - $D \equiv 1 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(D + 1) = 1 \oplus 0 = 1$
        - $g(4x + 2) \oplus g(4y + 2) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 1) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 4) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 3) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$

      - $0, 1$ には到達できるが、 $2$ には到達できない

    - $D \equiv 3 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(D + 1) = 1 \oplus 0 = 1$
        - $g(4x + 2) \oplus g(4y + 4) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 3) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 2) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 1) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$

      - $0, 1$ には到達できるが、 $2$ には到達できない

  - よって、 $g(X + 1 + 1) = 2$ が成立する。

- $g(X + 1 + 2) = g(D + 4)$

  - 攻撃遷移で到達可能な状態は $\lbrace 3, 5, 6 \cdots , D - 1, 0, 2 \rbrace$ であり、 $1$ に到達不可能。
  - 分裂遷移で到達可能かを下記の 2 パターンで議論する。

    - $D \equiv 1 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(D + 2) = 1 \oplus 2 = 3$
        - $g(2) \oplus g(D + 1) = 2 \oplus 0 = 2$
        - $g(4x + 3) \oplus g(4y + 2) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 1) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 4) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 3) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$

      - $0$ には到達できるが、 $1$ には到達できない

    - $D \equiv 3 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(D + 2) = 1 \oplus 2 = 3$
        - $g(2) \oplus g(D + 1) = 2 \oplus 0 = 2$
        - $g(4x + 3) \oplus g(4y + 4) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 3) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 2) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 1) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$

      - $0$ には到達できるが、 $1$ には到達できない

  - よって、 $g(X + 1 + 2) = 1$ が成立する。

- $g(X + 1 + 3) = g(D + 5)$

  - 攻撃遷移で到達可能な状態は $\lbrace 5, 6 \cdots , D - 1, 0, 2, 1 \rbrace$ であり、 $3$ に到達不可能。
  - 分裂遷移で到達可能かを下記の 2 パターンで議論する。

    - $D \equiv 1 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(D + 3) = 1 \oplus 1 = 0$
        - $g(2) \oplus g(D + 2) = 2 \oplus 2 = 0$
        - $g(3) \oplus g(D + 1) = 4 \oplus 0 = 4$
        - $g(4x + 4) \oplus g(4y + 2) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 1) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 4) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 3) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$

      - $0, 1, 2$ には到達できるが、 $3$ には到達できない

    - $D \equiv 3 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(D + 3) = 1 \oplus 1 = 0$
        - $g(2) \oplus g(D + 2) = 2 \oplus 2 = 0$
        - $g(3) \oplus g(D + 1) = 4 \oplus 0 = 4$
        - $g(4x + 4) \oplus g(4y + 4) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
        - $g(4x + 1) \oplus g(4y + 3) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 2) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 1) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$

      - $0, 1, 2$ には到達できるが、 $3$ には到達できない$

  - よって、 $g(X + 1 + 3) = 3$ が成立する。

- $g(X + 1 + 4) = g(D + 6)$

  - 攻撃遷移で到達可能な状態は $\lbrace 6 \cdots , D - 1, 0, 2, 1, 3 \rbrace$ であり、 $4$ に到達不可能。
  - 分裂遷移で到達可能かを下記の 2 パターンで議論する。

    - $D \equiv 1 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(D + 4) = 1 \oplus 3 = 2$
        - $g(2) \oplus g(D + 3) = 2 \oplus 1 = 3$
        - $g(3) \oplus g(D + 2) = 4 \oplus 2 \equiv 2 \pmod 4$
        - $g(4) \oplus g(D + 1) = 3 \oplus 0 = 3$
        - $g(4x + 1) \oplus g(4y + 2) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 1) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 4) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 3) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$

      - $0, 1, 2, 3$ には到達できるが、 $4$ には到達できない$

    - $D \equiv 3 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y$ は非負整数)

        - $g(1) \oplus g(D + 4) = 1 \oplus 3 = 2$
        - $g(2) \oplus g(D + 3) = 2 \oplus 1 = 3$
        - $g(3) \oplus g(D + 2) = 4 \oplus 2 \equiv 2 \pmod 4$
        - $g(4) \oplus g(D + 1) = 3 \oplus 0 = 3$
        - $g(4x + 1) \oplus g(4y + 4) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
        - $g(4x + 2) \oplus g(4y + 3) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$
        - $g(4x + 3) \oplus g(4y + 2) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
        - $g(4x + 4) \oplus g(4y + 1) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$

      - $0, 1, 2, 3$ には到達できるが、 $4$ には到達できない$

  - よって、 $g(X + 1 + 4) = 4$ が成立する。

したがって、 $s = 0$ の場合に命題が成立する。

ここで $s = n$ で命題が成立すると仮定する。 $s = n + 1$ の場合を考える。

- 仮定より、下記が言える。

  - $g(Xt + 1 + 4(n + 1) + 1) = g(Xt + 1 + 4n + 1) + 4$
  - $g(Xt + 1 + 4(n + 1) + 2) = g(Xt + 1 + 4n + 2) + 4$
  - $g(Xt + 1 + 4(n + 1) + 3) = g(Xt + 1 + 4n + 3) + 4$
  - $g(Xt + 1 + 4(n + 1) + 4) = g(Xt + 1 + 4n + 4) + 4$

したがって、 $s = n + 1$ も $s = n$ と同様に議論できることから、命題が成立する。

- ここで、 $g(X + 1 + D + 1)$ を考える。
  - これは、 $g(X + 1) = 0$ に攻撃遷移で到達できない最小の状態である。
  - また、 $X + 1 + D + 1 \equiv 1 \pmod 2$ であるため、分裂遷移で $0$ に到達することが不可能である。

したがって、 $s$ に関連する項が $D$ 項分だけ従うことも成立する。

(弐) $t = 1, 2, \cdots , n$ で命題が成立すると仮定する。 $t = n + 1$ の場合

- $g(X(n + 1) + 1) = g((D + 1)(n + 1) + 1)$

  - 攻撃遷移で到達可能な状態を考えると、直近 $D$ 項が $t = n$ の周期に従うため、 $0$ に到達できない。
  - また、 $(D + 1)(n + 1) + 1 \equiv 1 \pmod 2$ であるため、分裂遷移でも $0$ に到達てきない。
  - したがって、 $g(X(n + 1) + 1) = 0$

- $g(X(n + 1) + 1 + 1) = g((D + 1)(n + 1) + 2)$

  - 攻撃遷移で到達可能な状態は $\lbrace 1, 3, 4, 6, \cdots , D, 0 \rbrace$ であり、 $2$ に到達不可能。
  - 分裂遷移で到達可能かを下記の 2 パターンで議論する。

    - $D \equiv 1 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w$ は非負整数)

        - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1) = (Xz + 1 + 4x + 1) \oplus 0 \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 1) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 4) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$
          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 3) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 2) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$

        - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 1) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 4) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 3) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 2) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$

      - $0, 1$ には到達できるが、 $2$ には到達できない$

    - $D \equiv 3 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w$ は非負整数)

        - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1) = (4x + 1) \oplus 0 \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 3) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 2) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 1) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 4) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$

        - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 3) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 2) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$
          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 1) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 4) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$

      - $0, 1$ には到達できるが、 $2$ には到達できない$

  - よって、 $g(X(n + 1) + 1 + 1) = 2$ が成立する。

- $g(X(n + 1) + 1 + 2) = g((D + 1)(n + 1) + 3)$

  - 攻撃遷移で到達可能な状態は $\lbrace 3, 4, 6, \cdots , D, 0, 2 \rbrace$ であり、 $1$ に到達不可能。
  - 分裂遷移で到達可能かを下記の 2 パターンで議論する。

    - $D \equiv 1 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w$ は非負整数)

        - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1) = (4x + 2) \oplus 0 \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 1) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 4) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 3) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 2) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$

        - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 1) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 4) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 3) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 2) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$

      - $0$ には到達できるが、 $1$ には到達できない$

    - $D \equiv 3 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w$ は非負整数)

        - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1) = (4x + 2) \oplus 0 \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 3) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 2) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$
          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 1) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 4) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$

        - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 3) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 2) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$
          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 1) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 4) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$

      - $0$ には到達できるが、 $1$ には到達できない$

  - よって、 $g(X(n + 1) + 1 + 2) = 1$ が成立する。

- $g(X(n + 1) + 1 + 3) = g((D + 1)(n + 1) + 4)$

  - 攻撃遷移で到達可能な状態は $\lbrace 4, 6, \cdots , D, 0, 2, 1 \rbrace$ であり、 $3$ に到達不可能。
  - 分裂遷移で到達可能かを下記の 2 パターンで議論する。

    - $D \equiv 1 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w$ は非負整数)

        - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1) = (4x + 4) \oplus 0 \equiv 0 \pmod 4$
          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 1) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 4) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 3) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 2) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$

        - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 1) = (4x + 3) \oplus (4y + 2) \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 4) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$
          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 3) = (4x + 2) \oplus (4y + 3) \equiv 1 \pmod 4$
          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 2) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$

      - $0, 1, 2$ には到達できるが、 $3$ には到達できない$

    - $D \equiv 3 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w$ は非負整数)

      - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1) = (4x + 4) \oplus 0 \equiv 0 \pmod 4$
        - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 3) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
        - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 2) = (4x + 1) \oplus (4y + 1) \equiv 0 \pmod 4$
        - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 1) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
        - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 4) = (4x + 4) \oplus (4y + 4) \equiv 0 \pmod 4$

      - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

        - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 3) = (4x + 3) \oplus (4y + 3) \equiv 0 \pmod 4$
        - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 2) = (4x + 4) \oplus (4y + 1) \equiv 1 \pmod 4$
        - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 1) = (4x + 2) \oplus (4y + 2) \equiv 0 \pmod 4$
        - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 4) = (4x + 1) \oplus (4y + 4) \equiv 1 \pmod 4$

      - $0, 1, 2$ には到達できるが、 $3$ には到達できない$

  - よって、 $g(X(n + 1) + 1 + 3) = 3$ が成立する。

- $g(X(n + 1) + 1 + 4) = g((D + 1)(n + 1) + 5)$

  - 攻撃遷移で到達可能な状態は $\lbrace 6, \cdots , D, 0, 2, 1, 3 \rbrace$ であり、 $4$ に到達不可能。
  - 分裂遷移で到達可能かを下記の 2 パターンで議論する。

    - $D \equiv 1 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w$ は非負整数)

        - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1) = (4x + 3) \oplus 0 \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 1) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 4) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$
          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 3) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 2) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$

        - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 1) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 4) = (4x + 2) \oplus (4y + 4) \equiv 2 \pmod 4$
          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 3) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 2) = (4x + 3) \oplus (4y + 1) \equiv 2 \pmod 4$

      - $0, 1, 2, 3$ には到達できるが、 $4$ には到達できない

    - $D \equiv 3 \pmod 4$

      - 分裂遷移の遷移先は全て以下のいずれかのパターンで表せる ($x, y, z, w$ は非負整数)

        - (先頭 $X$ 項の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1) = (4x + 3) \oplus 0 \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 3) = (4x + 1) \oplus (4y + 3) \equiv 2 \pmod 4$
          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 2) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 1) = (4x + 4) \oplus (4y + 2) \equiv 2 \pmod 4$
          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 4) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$

        - (先頭 $X$ 項以降の周期) $\oplus$ (先頭 $X$ 項以降の周期) パターン

          - $g(Xz + 1 + 4x + 4) \oplus g(Xw + 1 + 4y + 3) = (4x + 4) \oplus (4y + 3) \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 1) \oplus g(Xw + 1 + 4y + 2) = (4x + 2) \oplus (4y + 1) \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 2) \oplus g(Xw + 1 + 4y + 1) = (4x + 1) \oplus (4y + 2) \equiv 3 \pmod 4$
          - $g(Xz + 1 + 4x + 3) \oplus g(Xw + 1 + 4y + 4) = (4x + 3) \oplus (4y + 4) \equiv 3 \pmod 4$

      - $0, 1, 2, 3$ には到達できるが、 $4$ には到達できない

  - よって、 $g(X(n + 1) + 1 + 4) = 4$ が成立する。

したがって、 $s = 0$ の場合に命題が成立する。

(弐) $s = n$ で命題が成立すると仮定する。 $s = n + 1$ の場合

- 仮定より、下記が言える。

  - $g(Xt + 1 + 4(n + 1) + 1) = g(Xt + 1 + 4n + 1) + 4$
  - $g(Xt + 1 + 4(n + 1) + 2) = g(Xt + 1 + 4n + 2) + 4$
  - $g(Xt + 1 + 4(n + 1) + 3) = g(Xt + 1 + 4n + 3) + 4$
  - $g(Xt + 1 + 4(n + 1) + 4) = g(Xt + 1 + 4n + 4) + 4$

したがって、 $s = n + 1$ も $s = n$ と同様に議論できることから、命題が成立する。

以上 (壱), (弐) より、命題が成立する。

(Ⅱ) (1), (Ⅱ) (2) が成立するため、(Ⅱ) が成立する。

したがって、全ての命題が成立するので、Grundy 数の一般項は初めに述べた通りである。
