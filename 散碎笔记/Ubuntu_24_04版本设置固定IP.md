# Ubuntu 24.04LTS设置固定IP

## 第一步：查看当前主机网络信息

### 获取网卡名、IP地址、子网掩码

```shell、
ifconfig
```

![image-20240530180118951](./Ubuntu_24_04%E7%89%88%E6%9C%AC%E8%AE%BE%E7%BD%AE%E5%9B%BA%E5%AE%9AIP.assets/image-20240530180118951.png)

通过上图所得，本机网卡名为：`ens32`，`IP`地址为：`20.20.20.20`，[子网掩码](https://so.csdn.net/so/search?q=子网掩码&spm=1001.2101.3001.7020)为：`255.255.255.0`

### 获取对应网关

```shell、
route -n
```

![image-20240530180159074](./Ubuntu_24_04%E7%89%88%E6%9C%AC%E8%AE%BE%E7%BD%AE%E5%9B%BA%E5%AE%9AIP.assets/image-20240530180159074.png)

通过上图所得，网关地址为：`192.168.15.2`

基本信息查到，可以进行配置文件的修改了。

## 第二步：修改配置文件

### 备份原配置文件

- 进入配置文件夹

    ```shell
    cd /etc/netplan
    ls -l
    ```

    - 可以查看到当前目录下的文件列表（如下图所示），一般而言，配置文件名为`01-network-manager-all.yaml`

    - ![image-20240530180620186](./Ubuntu_24_04%E7%89%88%E6%9C%AC%E8%AE%BE%E7%BD%AE%E5%9B%BA%E5%AE%9AIP.assets/image-20240530180620186.png)

- 可以把配置文件复制一个备份

    ```shell
    sudo cp 01-network-manager-all.yaml 01-network-manager-all.yaml.bak
    ```

### 编辑配置文件

```shell
sudo vim 01-network-manager-all.yaml
```

`注意`:格式要正确，每个冒号后要留一个空格，这里提供可复制版本，按照自己的稍微改一下即可！

```
# Let NetworkManager manage all devices on this system
network:
  ethernets:
    ens32:
      addresses: [192.168.15.132/24]          # 设置静态IP地址和掩码
      routes:                                 # 设置网关地址
       - to: default
         via: 192.168.15.2
      dhcp4: false                            # 禁用dhcp
      nameservers:
        addresses: [114.114.114.114, 8.8.8.8] # 设置主、备DNS
  version: 2
  renderer: NetworkManager
```

## 第三步：使配置生效且检查网络连接状况

配置完成后要执行下面的命令使配置生效。

```shell
sudo netplan apply
```

## 常见报错

### 1.配置文件权限设置过于开放

```shell
# 错误原文
** (generate:4356): WARNING **: 17:18:46.924: Permissions for /etc/netplan/01-network-manager-all.yaml are too open. Netplan configuration should NOT be accessible by others.
```

这个错误信息表明，`/etc/netplan/01-network-manager-all.yaml` 文件的权限设置过于开放，导致Netplan配置文件被其他用户访问是不安全的。Netplan需要该文件的权限设置为仅根用户或特定用户可以访问，以确保网络配置的安全性。

你可以通过以下步骤更正这个问题：

#### 检查当前文件权限
1. 打开终端。
2. 使用以下命令检查文件的当前权限：
   ```sh
   ls -l /etc/netplan/01-network-manager-all.yaml
   ```

#### 更改文件权限
要修正这个问题，确保文件权限设置为仅根用户可读写，其他用户不可访问。你可以使用以下命令来更改文件权限：

```sh
sudo chmod 600 /etc/netplan/01-network-manager-all.yaml
```

这将设置文件权限为：

- `6` (rw-)：表示所有者可以读和写。
- `0` (---)：表示组用户没有任何权限。
- `0` (---)：表示其他用户没有任何权限。

#### 验证权限
再次检查文件权限以确认更改已生效：

```sh
ls -l /etc/netplan/01-network-manager-all.yaml
```

输出应该类似于：

```sh
-rw------- 1 root root  <size> <date> /etc/netplan/01-network-manager-all.yaml
```

这表示文件现在只有根用户可以读和写。

#### 应用更改
如果你对Netplan配置文件进行了任何更改，请记得应用这些更改：

```sh
sudo netplan apply
```

这些步骤将确保Netplan配置文件的权限设置正确，并解决你遇到的警告问题。

### 2.gateway4在新的Netplan配置中已被弃用

```shell
#错误原文
** (generate:4356): WARNING **: 17:18:46.924: `gateway4` has been deprecated, use default routes instead.
See the 'Default routes' section of the documentation for more details.
```

这个警告信息表明，`gateway4` 在新的Netplan配置中已被弃用，建议使用默认路由配置来替代。Netplan开发团队推荐使用默认路由（default routes）配置方法来指定网关。

#### 更改Netplan配置文件

你需要修改Netplan配置文件，移除`gateway4`配置项，改用默认路由配置。下面是一个示例：

##### 原配置文件（使用`gateway4`）
```yaml
network:
  version: 2
  ethernets:
    eth0:
      dhcp4: no
      addresses:
        - 192.168.1.100/24
      gateway4: 192.168.1.1
      nameservers:
        addresses:
          - 8.8.8.8
          - 8.8.4.4
```

##### 新配置文件（使用默认路由）
```yaml
network:
  version: 2
  ethernets:
    eth0:
      dhcp4: no
      addresses:
        - 192.168.1.100/24
      routes:
        - to: default
          via: 192.168.1.1
      nameservers:
        addresses:
          - 8.8.8.8
          - 8.8.4.4
```

#### 详细步骤

1. **编辑Netplan配置文件**
   使用你喜欢的文本编辑器，例如`nano`或`vi`，编辑Netplan配置文件：

   ```sh
   sudo nano /etc/netplan/01-network-manager-all.yaml
   ```

2. **更新配置**
   根据上面的示例，移除`gateway4`行，添加默认路由配置：

   ```yaml
   network:
     version: 2
     ethernets:
       eth0:
         dhcp4: no
         addresses:
           - 192.168.1.100/24
         routes:
           - to: default
             via: 192.168.1.1
         nameservers:
           addresses:
             - 8.8.8.8
             - 8.8.4.4
   ```

3. **保存并退出编辑器**
   在`nano`中，按`Ctrl+O`保存文件，然后按`Ctrl+X`退出编辑器。

4. **应用Netplan配置**
   使用以下命令应用新配置：

   ```sh
   sudo netplan apply
   ```

#### 验证配置

你可以使用以下命令来验证网络配置是否正确应用：

```sh
ip route
```

输出中应该包含默认路由设置，如：

```sh
default via 192.168.1.1 dev eth0
```

这些步骤将确保你的Netplan配置符合新的配置标准，避免使用已弃用的`gateway4`配置项。
