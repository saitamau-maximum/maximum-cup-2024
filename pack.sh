PROBLEM_NAME=$1
SOLUTION=$2
SOLUTION_FILE=$PROBLEM_NAME/$SOLUTION/main.cc

if [ -z $PROBLEM_NAME ] || [ -z $SOLUTION ]; then
  echo "Usage: ./pack.sh PROBLEM_NAME SOLUTION"
  echo "Example: ./pack.sh three-coins sol-cpp-ac"
  echo "Place the solution cpp file to PROBLEM_NAME/SOLUTION/main.cc"
  exit 1
fi

# Check if the problem exists
if [ ! -d $PROBLEM_NAME ]; then
  echo "Problem $PROBLEM_NAME not found."
  exit 1
fi

# Check if the solution exists
if [ ! -f $SOLUTION_FILE ]; then
  echo "Solution $SOLUTION_FILE not found."
  exit 1
fi

# Check if the testcases exist
if [ ! -d $PROBLEM_NAME/tests ]; then
  echo "Testcases $PROBLEM_NAME/tests not found."
  exit 1
fi

# Check if the zip command exists
if ! command -v zip &> /dev/null; then
  echo "zip command not found."
  exit 1
fi

# Make temporary directory
echo "Making temporary directory..."
mkdir -p tmp
cd tmp
mkdir input
mkdir output

# Copy the solution and inputs
echo "Copying solution and inputs..."
cp ../$SOLUTION_FILE main.cc
cp ../$PROBLEM_NAME/tests/*.in input/
for input in input/*.in; do
  mv $input $(dirname $input)/$(basename $input .in).txt
done

# Compile the solution
echo "Compiling solution..."
g++ -std=c++2a -O2 -I../_common -o main main.cc

# Run the solution
echo "Running solution..."
for input in input/*.txt; do
  output=output/$(basename $input)
  ./main < $input > $output
done

# Zip the outputs
echo "Zipping outputs..."
zip -r ../$PROBLEM_NAME.zip input output

# Clean up
echo "Cleaning up..."
cd ..
rm -rf tmp

echo "Done."
