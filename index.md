<h2>{{ site.data.list.docs_list_title }}</h2>
<ul>
{% for item in site.data.list.toc %}
   <h3>{{ item.title }}</h3>
   {% for entry in item.subfolderitems %}
      <li><a href="https://soupman123.github.io/SoupOS{{ entry.url }}">{{ entry.page }}</a></li>
   {% endfor %}
{% endfor %}
</ul>

### What is SoupOS?
[SoupOS](http://github.com) is a computer operating system currently maintained & written by [Soupman123](https://github.com/Soupman123/). SoupOS is a hobby operating system not written to compete with other operating systems, and is currently just a small project.

### What can SoupOS do?
Some of the main features inlude but are not limmited to at this moment:
```
PS/2 Mouse
Basic Keyboard
Simple text rendering
PCI Devices
```

### How can I get involved / started?
To get involved you can download the source code [here](https://github.com/Soupman123/SoupOS/archive/master.zip), or download the compiled operating system image [here](https://github.com/Soupman123/SoupOS/raw/master/kernel/bin/SoupOS.img). There are also some great resources over at [@absurdponcho](https://github.com/Absurdponcho)['s operating system](https://github.com/Absurdponcho/PonchoOS) if you wouldlike to learn more about operating system development.

### Credits
Thanks to [Poncho](https://github.com/Absurdponcho/) for helping get me into OSdev and for providing great educational resources.
[Soup#9370](https://discord.com/users/698622052059316285/) on [Discord](https://discord.com)

### Future
These are the features that are planned to be added in the near future.
```
Double buffering
USB support
Advanced shape rendering
```
