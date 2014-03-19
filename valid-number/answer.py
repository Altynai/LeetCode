
class Solution:
    # @param s, a string
    # @return a boolean
    def isNumber(self, s):
        try:
        	float(s)
        except:
        	return False
        else:
        	return True
