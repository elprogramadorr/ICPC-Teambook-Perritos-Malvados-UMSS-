import subprocess
import os

def get_sections():
    sections = []
    section_name = None 
    with open('contents.txt', 'r') as f:
        for line in f:
            if '#' in line: line = line[:line.find('#')]
            line = line.strip()
            if len(line) == 0: continue
            if line[0] == '[':
                if section_name is not None:
                    sections.append((section_name, subsections))
                section_name = line[1:-1]
                subsections = []
            else:
                tmp = line.split('\t', 1)
                if len(tmp) == 1:
                    raise ValueError('Subsection parse error: %s' % line)
                filename = tmp[0]
                subsection_name = tmp[1]
                if subsection_name is None:
                    raise ValueError('Subsection given without section')
                subsections.append((filename, subsection_name))
    return sections

def get_style(filename):
    ext = filename.lower().split('.')[-1]
    if ext in ['c', 'cc', 'cpp', 'h']:
        return 'cpp'
    elif ext in ['java']:
        return 'java'
    elif ext in ['py']:
        return 'py'
    else:   
        return 'txt'

def texify(s):
    return s

def get_tex(sections):
    tex = ''
    for (section_name, subsections) in sections:
        tex += '\\section{%s}\n' % texify(section_name)
        for (filename, subsection_name) in subsections:
            tex += '\\subsection{%s}\n' % texify(subsection_name)
            tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s}\n' % (get_style(filename), filename)
            tex += '\\hrulefill\n'
        tex += '\n'
    return tex

if __name__ == "__main__":
    sections = get_sections()
    tex = get_tex(sections)
    with open('contents.tex', 'w') as f:
        f.write(tex)
    latexmk_options = ["latexmk","-pdf", "notebook.tex"]
    subprocess.call(latexmk_options)
    remove_files = ["notebook.fls", "notebook.aux", "notebook.fdb_latexmk", 
    "notebook.log", "notebook.out", "notebook.toc"]
    for file in remove_files:
        if os.path.exists(file):
            os.remove(file)