"""Test that we are able to print bitfield fields that cross a byte boundary"""

import lldb
from lldbsuite.test.lldbtest import *

class  BitFieldExprOnBoundaryTestCase(TestBase):

    def test_bitfield_expr_on_boundary(self):
        """ Test that we are able to print bitfield fields that cross a byte boundary """
        self.build()
        lldbutil.run_to_source_breakpoint(self, '// Break here', lldb.SBFileSpec("main.c"))
        self.expect_expr("f", result_value='None : (volatile Foo) $0 = (a = \'\x01\', b = \'\x02\')')
