filenames=(
  "01_random00_task1.in"
  "01_random01_task1.in"
  "01_random02_task1.in"
  "01_random03_task1.in"
  "01_random04_task1.in"
  "02_hand00_task1.in"
  "03_min00_task1.in"
  "03_min01_task1.in"
  "03_min02_task1.in"
  "03_max00_task1.in"
  "03_max01_task1.in"
  "03_max02_task1.in"
  "03_max03_task1.in"
  "01_random00_all.in"
  "01_random01_all.in"
  "01_random02_all.in"
  "01_random03_all.in"
  "01_random04_all.in"
  "02_hand00_all.in"
  "03_max00_all.in"
  "03_max01_all.in"
  "03_max02_all.in"
  "03_max03_all.in"
)

# Check if gen.out exists
if [ ! -f gen.out ]; then
  echo "gen.out not found. Please compile gen.cpp first."
  exit 1
fi

echo "Generating ${#filenames[@]} test cases..."
for filename in "${filenames[@]}"; do
  echo "Generating $filename..."
  ./gen.out $filename > $filename
done
echo "Done."
