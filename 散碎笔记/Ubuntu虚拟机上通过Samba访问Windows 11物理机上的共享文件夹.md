# Ubuntu虚拟机上通过Samba访问Windows 11物理机上的共享文件夹

要在Ubuntu虚拟机上通过Samba访问Windows 11物理机上的共享文件夹，您需要按照以下步骤进行设置。这里假设您已经完成了一些基本的准备工作，比如确保虚拟机网络配置正确，并且Windows 11和Ubuntu可以互相ping通。

### 1. 在Windows 11上设置共享文件夹

1. **选择文件夹**：在Windows 11上选择您想要共享的文件夹。
2. **右键点击文件夹**，选择“属性”。
3. 转到“共享”选项卡，点击“共享”按钮。
4. 在共享对话框中，选择要共享的用户或组（如“Everyone”），并设置权限级别（读取/写入），然后点击“共享”。
5. 记录或记住共享文件夹的网络路径，例如：`\\<Windows计算机名或IP地址>\<共享文件夹名>`。

### 2. 在Ubuntu上安装Samba客户端

打开终端，输入以下命令来安装Samba客户端和相关的工具：

```bash
sudo apt update
sudo apt install samba-client cifs-utils
```

### 3. 在Ubuntu上挂载Windows共享文件夹

1. **创建挂载点**：在Ubuntu上创建一个目录，用于挂载Windows共享文件夹。例如：

   ```bash
   sudo mkdir /mnt/windows_share
   ```

2. **挂载共享文件夹**：使用以下命令挂载共享文件夹。需要根据您的实际情况替换`<Windows计算机名或IP地址>`和`<共享文件夹名>`：

   ```bash
   sudo mount -t cifs //<Windows计算机名或IP地址>/<共享文件夹名> /mnt/windows_share -o username=<Windows用户名>,password=<密码>,uid=<Ubuntu用户ID>,gid=<Ubuntu组ID>
   ```

   例如：

   ```bash
   sudo mount -t cifs //192.168.1.10/Shared /mnt/windows_share -o username=john,password=123456,uid=1000,gid=1000
   ```

   其中`uid`和`gid`可以通过`id -u`和`id -g`命令分别获取。

### 4. 验证挂载

使用以下命令查看是否成功挂载：

```bash
df -h
```

您应该能在输出中看到挂载的共享文件夹。

### 5. 设置开机自动挂载（可选）

如果您希望每次启动Ubuntu时自动挂载Windows共享文件夹，可以编辑`/etc/fstab`文件：

```bash
sudo nano /etc/fstab
```

添加以下一行：

```
//<Windows计算机名或IP地址>/<共享文件夹名> /mnt/windows_share cifs username=<Windows用户名>,password=<密码>,uid=<Ubuntu用户ID>,gid=<Ubuntu组ID> 0 0
```

保存并退出编辑器。

### 6. 卸载共享文件夹（可选）

如果您需要卸载共享文件夹，可以使用以下命令：

```bash
sudo umount /mnt/windows_share
```

通过以上步骤，您应该能够在Ubuntu虚拟机上通过Samba访问Windows 11物理机上的共享文件夹。如果有任何问题或需要进一步的帮助，请随时提问。