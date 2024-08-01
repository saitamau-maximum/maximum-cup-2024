filenames=(
  "01_random00_task1.in"
  "01_random01_task1.in"
  "01_random02_task1.in"
  "01_random03_task1.in"
  "01_random04_task1.in"
  "02_hand00_task1.in"
  "02_hand01_task1.in"
  "02_hand02_task1.in"
  "02_hand03_task1.in"
  "02_hand04_task1.in"
  "03_min00_task1.in"
  "03_min01_task1.in"
  "03_max00_task1.in"
  "03_max01_task1.in"
  "03_max02_task1.in"
  "03_max03_task1.in"
  "03_max04_task1.in"
  "03_max05_task1.in"
  "01_random00_all.in"
  "01_random01_all.in"
  "01_random02_all.in"
  "01_random03_all.in"
  "01_random04_all.in"
  "01_random05_all.in"
  "01_random06_all.in"
  "01_random07_all.in"
  "01_random08_all.in"
  "01_random09_all.in"
  "03_max00_all.in"
  "03_max01_all.in"
  "03_max02_all.in"
  "03_max03_all.in"
)

echo "Compiling generator..."
g++ -std=c++2a -O2 -Wall -Wextra -I../../_common -o gen.out generator.cc
if [ $? -ne 0 ]; then
  echo "Compilation failed."
  exit 1
fi

echo "Generating ${#filenames[@]} test cases..."
for filename in "${filenames[@]}"; do
  echo "Generating $filename..."
  ./gen.out $filename > $filename
done
echo "Done."
