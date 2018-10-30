class Solution:
    
    def process(self, email):
        local, domain = email.split('@')
        local = local.replace('.', '')
        local = local[:local.find('+')]
        return "{0}@{1}".format(local, domain)

    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        return len(set(map(self.process, emails)))

