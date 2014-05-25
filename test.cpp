#include "guid.h"

using namespace std;

int main(int argc, char *argv[])
{

  auto r1 = generateGuid();
  auto r2 = generateGuid();
  auto r3 = generateGuid();

  Guid s1("7bcd757f-5b10-4f9b-af69-1a1f226f3b3e");
  Guid s2("16d1bd03-09a5-47d3-944b-5e326fd52d27");
  Guid s3("fdaba646-e07e-49de-9529-4499a5580c75");
  Guid s4("7bcd757f-5b10-4f9b-af69-1a1f226f3b3e");

  if (r1 == r2 || r1 == r3 || r2 == r3)
  {
    cout << "FAIL - not all random guids are different" << endl;
    return 1;
  }

  if (s1 == s2)
  {
    cout << "FAIL - s1 and s2 should be different" << endl;
    return 1;
  }

  if (s1 != s4)
  {
    cout << "FAIL - s1 and s4 should be equal" << endl;
    return 1;
  }

  stringstream ss1;
  ss1 << s1;
  if (ss1.str() != "7bcd757f-5b10-4f9b-af69-1a1f226f3b3e")
  {
    cout << "FAIL - string generated from s1 is wrong" << endl;
    return 1;
  }

  stringstream ss2;
  ss2 << s2;
  if (ss2.str() != "16d1bd03-09a5-47d3-944b-5e326fd52d27")
  {
    cout << "FAIL - string generated from s2 is wrong" << endl;
    return 1;
  }

  stringstream ss3;
  ss3 << s3;
  if (ss3.str() != "fdaba646-e07e-49de-9529-4499a5580c75")
  {
    cout << "FAIL - string generated from s3 is wrong" << endl;
    return 1;
  }

  cout << "All tests passed!" << endl;

  return 0;
}
