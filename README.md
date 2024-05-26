# Maximum-Cup 2024

問題を管理するためのリポジトリ

## ディレクトリ構成

```plaintext
│
├── README.md (このファイル)
├── .gitignore
├── LICENSE
│
├── .clang-format (フォーマット用)
├── .editorconfig
│
├── _common/testlib.h (https://github.com/MikeMirzayanov/testlib を参照)
│
├── requirements.txt (Python の依存関係)
├── requirements.lock (Python の依存関係のバージョン固定)
│
├── PROJECT (プロジェクトの設定)
│
└── (各問題のディレクトリ)
    ├── PROBLEM (問題の設定)
    ├── tests (テストケース)
    │   ├ TESTSET (テストケースの設定)
    │   ├ 00_sampleX.in (サンプルケース, 0-indexed)
    │   ├ 10_randomX.in (ランダムケース, 0-indexed)
    │   ├ 20_cornerX.in (コーナーケース, 0-indexed)
    │   ├ generator.cc (ランダムケースの生成器)
    │   ├ validator.cc (入力の検証)
    │   └ judge.cc (出力の判定)
    ├── sol-<lang>-<expected-judge> 解法、下記参照
    └── README.md (問題文, 解法説明, コーナーテスト説明など)
```

## Quickstart

[Rime+のススメ](https://qiita.com/hiroshi-cl/items/fbd0d0963d8207d33bc6) を読みましょう

### インストール

入力生成器として [Rime](https://github.com/icpc-jag/rime) を用いるため、インストールする。venv などを使うと良い。

```bash
pip install rime
```

requirements.txt に書いてあるので、以下のコマンドでもインストールできる

```bash
pip install -r requirements.txt
```

なお、Windows 上で動かす場合不安定らしいので注意

### 問題作り

```bash
rime add . problem <problem-name>
```

`PROBLEM` ファイルの内容 (一部)

```py
pid='<problem-name>' # 問題のID、ディレクトリ名と同一 (上記コマンドの <problem-name>)
problem(
  time_limit=1.0, # 実行時間制限 (秒)
  id=pid,
  title="問題名", # 問題名 (英語がいい)
)
```

### 想定解や嘘解法など追加

```bash
rime add <problem-name> solution <sol-name>
```

`<sol-name>` は、次の形式にしてください

```bnf
<sol-name> ::= sol-<lang>-<expected-judge>
<lang> ::= 'cpp' | 'py' | 'java' | 'c' | (その他言語の拡張子)
<expected-judge> ::= <verdict> | 'partial'<digit> (partial: 部分点のみ AC 解法)
<verdict> ::= 'ac' | 'wa' | 'tle' | (AtCoder におけるジャッジ結果)
```

`SOLUTION` ファイルの内容

- cpp 使うなら `cxx_solution` をコメントアウトし、`main.cc` ファイルを作成する
- もし AC 以外の想定なら引数として `challenge_cases=[]` を追加する
- スコアは `expected_score` で設定。まあ一律で 1 でいいと思う

### テストケース追加

```bash
rime add <parent_problem_dir_name> testset tests
```

サンプルは `00_sampleX.in` という名前で `tests` ディレクトリに入れる。
なお、 `X` は 00, 01, 02, ... というように連番にする。(0-indexed)

ランダムケース (`generator.cc` で作ったもの) は `10_randomX.in` という名前にする。
`generator.cc` には違う Seed 値をコマンドライン引数として与えて、異なるケースを生成するようにする。

メモ(`generator.cc` のコンパイル): `g++ -std=c++20 -O2 -Wall -I ../../_common -o gen.out generator.cc`

メモ(テストの生成): `gen(){ ./gen.out $1 > $1; }` として `gen <出力先ファイル>`

コーナーケース・手作業用意ケースは `20_handX.in` とかの名前にする。

Max ケース・ Min ケースは `30_maxX.in` とかの名前にする。

`TESTSET` ファイルの内容

- Input generators: 入力を生成するプログラム
- Input validators: 入力がフォーマット・制約を満たしているかをチェックするプログラム
- Output judges: 出力が正しいかをチェックするプログラム
- Reactives: いわゆるインタラクティブ問題のためのプログラム
- Extra Testsets: その他の設定

### ビルドとテスト

```bash
rime build <problem-name>
```

```bash
rime test <problem-name>
```

## testlib.h の使い方

Codeforces の開発者 Mike Mirzayanov さんが作った、テストケースとかにかかわるライブラリ。
<https://github.com/MikeMirzayanov/testlib>

なんか「使い方が最も簡単にわかる方法は、ソースコードを見ろ」らしいので、見てください。
(`/checkers`, `/validators`, `/generators`, `/interactors` のファイルたちは使い方の例っぽい)
