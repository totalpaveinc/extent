Help()
{
   # Display Help
   echo "Script to optionally build and run the tests"
   echo
   echo "Syntax: test.sh [-b]"
   echo "options:"
   echo "b     Build before running the tests"
   echo
}

while getopts ":hb" option; do
    case $option in
        h) # Help
            Help
            exit;;
        b) # Build
            cmake -S=specs -B=specs/cmake
    esac
done

Make -C ./specs/cmake