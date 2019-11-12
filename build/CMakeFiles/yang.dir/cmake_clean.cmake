file(REMOVE_RECURSE
  "libyang.pdb"
  "libyang.so.1.3.0"
  "libyang.so"
  "libyang.so.1"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/yang.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
