using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RNG.ComApi
{
    public interface IDllApi
    {
        int PostArray(UInt64[] numberArray);
    }

    public class DllApi : IDllApi
    {
        public int PostArray(UInt64[] numberArray)
        {
            if (numberArray.Length > 0) return 0;
            return 1;
        }
    }
}
