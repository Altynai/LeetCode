class Solution:
    def entityParser(self, text: str) -> str:
        replaces = (
            ("&frasl;", "/"),
            ("&lt;", "<"),
            ("&gt;", ">"),
            ("&apos;", "'"),
            ("&quot;", "\""),
            ("&amp;", "&"),
        )
        for old, cur in replaces:
            text = text.replace(old, cur)
        return text

