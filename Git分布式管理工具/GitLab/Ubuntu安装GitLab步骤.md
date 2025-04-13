# Ubuntu安装GitLab步骤

## Ubuntu安装gitlab

---

### 🤖 Assistant

在Ubuntu系统上安装GitLab可以通过以下步骤完成。我们将使用官方提供的脚本进行安装和配置。

### 1. 更新系统包
首先，确保你的系统是最新的：

```bash
sudo apt update
sudo apt upgrade -y
```

### 2. 安装依赖项
GitLab需要一些依赖项，如`curl`、`openssh-server`等。你可以通过以下命令安装它们：

```bash
sudo apt install -y curl openssh-server ca-certificates postfix
```

在安装`postfix`时，系统会提示你选择配置类型。你可以选择“Internet Site”并设置你的域名。

### 3. 下载并运行GitLab安装脚本
GitLab提供了一个自动化安装脚本，可以简化安装过程。你可以通过以下命令下载并运行该脚本：

```bash
curl https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | sudo bash
```

然后，安装GitLab CE（社区版）：

```bash
sudo apt install -y gitlab-ce
```

### 4. 配置GitLab
安装完成后，运行以下命令来配置GitLab：

```bash
sudo gitlab-ctl reconfigure
```

此命令将会配置并启动所有必要的服务。

### 5. 访问GitLab
默认情况下，GitLab将使用你系统的IP地址或主机名作为Web界面的URL。你可以在浏览器中访问以下地址来打开GitLab：

```
http://your_server_ip_or_hostname
```

首次访问时，系统会提示你设置一个管理员密码。

### 6. 防火墙设置（可选）
如果系统启用了防火墙`ufw`，你需要确保开放HTTP和HTTPS端口：

```bash
sudo ufw allow http
sudo ufw allow https
```

### 7. 后续配置（可选）
你可以通过编辑`/etc/gitlab/gitlab.rb`文件来进一步配置GitLab，例如修改域名、启用HTTPS等。修改后，记得运行以下命令使更改生效：

```bash
sudo gitlab-ctl reconfigure
```

### 8. 启动和停止GitLab
你可以使用以下命令来启动、停止或重启GitLab服务：

```bash
# 启动GitLab
sudo gitlab-ctl start

# 停止GitLab
sudo gitlab-ctl stop

# 重启GitLab
sudo gitlab-ctl restart
```

### 9. 卸载GitLab（可选）
如果你需要卸载GitLab，可以使用以下命令：

```bash
sudo gitlab-ctl uninstall
sudo apt remove --purge gitlab-ce
sudo rm -rf /opt/gitlab
sudo rm -rf /etc/gitlab
```

### 总结
通过以上步骤，你可以在Ubuntu系统上成功安装并配置GitLab。GitLab是一个非常强大的代码托管和协作平台，适合团队开发和个人项目使用。

如果你有进一步的需求或问题，欢迎继续提问！

---

## 如何修改/etc/gitlab/gitlab.rb

---

### 🤖 Assistant

要修改 `/etc/gitlab/gitlab.rb` 文件以更改 GitLab 的 URL 或其他配置，请按照以下步骤操作：

---

### 1. 打开 `/etc/gitlab/gitlab.rb` 文件
使用文本编辑器（如 `nano` 或 `vim`）打开配置文件：

```bash
sudo nano /etc/gitlab/gitlab.rb
```

---

### 2. 修改 `external_url` 配置
在配置文件中找到 `external_url` 这一行。默认情况下，它可能被注释掉，或者设置为默认的 URL（如 `http://gitlab.example.com`）。

将其修改为你想要的 URL 或 IP 地址。例如：

```ruby
external_url 'http://your-domain.com'
```

或者使用 IP 地址：

```ruby
external_url 'http://192.168.1.100'
```

如果需要使用 HTTPS，可以将协议改为 `https`：

```ruby
external_url 'https://your-domain.com'
```

**注意：**
- 如果使用 HTTPS，你还需要配置 SSL 证书。
- 如果使用 IP 地址而不是域名，确保客户端可以通过该 IP 地址访问 GitLab。

---

### 3. 其他可选配置
在 `/etc/gitlab/gitlab.rb` 文件中，你还可以修改其他配置。例如：

1. **邮件服务器配置：**
   ```ruby
   gitlab_rails['smtp_enable'] = true
   gitlab_rails['smtp_address'] = "smtp.example.com"
   gitlab_rails['smtp_port'] = 587
   gitlab_rails['smtp_user_name'] = "your-email@example.com"
   gitlab_rails['smtp_password'] = "your-email-password"
   gitlab_rails['smtp_domain'] = "example.com"
   gitlab_rails['smtp_authentication'] = "login"
   gitlab_rails['smtp_enable_starttls_auto'] = true
   ```

2. **LDAP 身份验证配置：**
   ```ruby
   gitlab_rails['ldap_enabled'] = true
   gitlab_rails['ldap_servers'] = YAML.load <<-EOS
     main:
       label: 'LDAP'
       host: 'ldap.example.com'
       port: 389
       uid: 'uid'
       bind_dn: 'cn=admin,dc=example,dc=com'
       password: 'password'
       encryption: 'plain'
       active_directory: true
   EOS
   ```

3. **其他高级配置：**
   - `nginx` 配置
   - `gitlab-shell` 配置
   - `redis` 配置
   - `postgresql` 配置

---

### 4. 保存并退出
编辑完成后，保存文件并退出编辑器。例如，在 `nano` 中，按 `Ctrl + O` 保存，然后按 `Ctrl + X` 退出。

---

### 5. 重新配置 GitLab
运行以下命令使更改生效：

```bash
sudo gitlab-ctl reconfigure
```

此命令会重新加载配置并重启 GitLab 服务。

---

### 6. 检查 GitLab 是否正常运行
重新配置完成后，检查 GitLab 是否正常运行：

```bash
sudo gitlab-ctl status
```

确保所有服务（如 `unicorn`、`sidekiq`、`nginx` 等）都正常运行。

---

### 7. 访问 GitLab
在浏览器中访问你设置的 `external_url`（如 `http://your-domain.com`），确保可以正常打开 GitLab。

---

### 8. HTTPS 配置（可选）
如果使用 `https`，你需要配置 SSL 证书。可以通过 Let's Encrypt 自动获取证书，也可以手动配置。

#### 自动配置（使用 Let's Encrypt）
在 `/etc/gitlab/gitlab.rb` 中添加以下配置：

```ruby
letsencrypt['enable'] = true
letsencrypt['contact_emails'] = ['your-email@example.com']
```

然后重新配置：

```bash
sudo gitlab-ctl reconfigure
```

#### 手动配置
将你的 SSL 证书文件（如 `cert.pem` 和 `key.pem`）上传到服务器，然后在 `/etc/gitlab/gitlab.rb` 中配置：

```ruby
nginx['ssl_certificate'] = "/path/to/cert.pem"
nginx['ssl_certificate_key'] = "/path/to/key.pem"
```

重新配置后生效。

---

### 总结
通过修改 `/etc/gitlab/gitlab.rb` 文件中的 `external_url` 配置，你可以轻松更改 GitLab 的访问地址。完成修改后，运行 `sudo gitlab-ctl reconfigure` 使更改生效。

如果你有其他需求或问题，欢迎继续提问！

---

## 遇到错误一

HTTP 502: Waiting for GitLab to boot

It can take up to a few minutes for GitLab to boot completely.

This page will automatically reload every 5 seconds.


---

### 🤖 Assistant

HTTP 502 错误通常是由于 GitLab 启动过程中某些服务未完全启动或配置错误导致的。以下是解决该问题的步骤：

---

### 1. 确认 GitLab 服务状态
运行以下命令检查 GitLab 服务状态：

```bash
sudo gitlab-ctl status
```

确保所有服务（如 `unicorn`、`sidekiq`、`nginx`、`postgresql` 等）都正常运行。如果有服务未启动，可以尝试手动启动：

```bash
sudo gitlab-ctl start
```

---

### 2. 检查日志文件
查看 GitLab 的日志文件，找出问题原因。

1. **检查 `nginx` 日志：**
   ```bash
   sudo tail -f /var/log/gitlab/nginx/error.log
   ```

2. **检查 `unicorn` 日志：**
   ```bash
   sudo tail -f /var/log/gitlab/unicorn/unicorn_stderr.log
   sudo tail -f /var/log/gitlab/unicorn/unicorn_stdout.log
   ```

3. **检查 `sidekiq` 日志：**
   ```bash
   sudo tail -f /var/log/gitlab/sidekiq/current
   ```

4. **检查 `postgresql` 日志：**
   ```bash
   sudo tail -f /var/log/gitlab/postgresql/current
   ```

根据日志中的错误信息，调整配置或修复问题。

---

### 3. 验证数据库连接
如果数据库连接失败，GitLab 也会返回 502 错误。检查 PostgreSQL 是否正常运行：

```bash
sudo gitlab-rake gitlab:check
```

如果数据库有问题，可以尝试修复：

1. **进入 PostgreSQL 控制台：**
   ```bash
   sudo gitlab-psql
   ```

2. **检查数据库状态：**
   ```sql
   \l
   ```

3. **修复数据库（如果需要）：**
   ```bash
   sudo gitlab-rake db:migrate
   ```

---

### 4. 检查内存和资源不足
如果服务器内存不足，GitLab 可能无法正常启动。检查系统资源使用情况：

```bash
free -h
```

如果内存不足，可以尝试增加交换空间：

```bash
sudo fallocate -l 2G /swapfile
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
```

---

### 5. 检查配置文件
确保 `/etc/gitlab/gitlab.rb` 中的配置正确无误。特别是以下配置：

1. **`external_url`：**
   ```ruby
   external_url 'http://your-domain.com'
   ```

2. **`nginx` 配置：**
   ```ruby
   nginx['enable'] = true
   ```

3. **`unicorn` 配置：**
   ```ruby
   unicorn['worker_processes'] = 2
   ```

修改配置后，重新配置 GitLab：

```bash
sudo gitlab-ctl reconfigure
```

---

### 6. 检查端口冲突
GitLab 默认使用以下端口：
- 80（HTTP）
- 443（HTTPS）
- 8080（GitLab Workhorse）

检查是否有其他服务占用了这些端口：

```bash
sudo netstat -tuln | grep -E ':80|:443|:8080'
```

如果端口冲突，可以修改 GitLab 的端口配置，或停止占用端口的服务。

---

### 7. 重启 GitLab
如果以上步骤未能解决问题，尝试完全重启 GitLab：

```bash
sudo gitlab-ctl restart
```

---

### 8. 防火墙设置
确保防火墙允许 HTTP（80）和 HTTPS（443）端口：

1. **开放端口（如果使用 `ufw`）：**
   ```bash
   sudo ufw allow http
   sudo ufw allow https
   ```

2. **检查防火墙状态：**
   ```bash
   sudo ufw status
   ```

---

### 9. DNS 解析
确保你的域名正确解析到 GitLab 服务器的 IP 地址。检查方法：

1. **本地测试：**
   ```bash
   ping your-domain.com
   ```

2. **检查 DNS 解析：**
   ```bash
   nslookup your-domain.com
   ```

---

### 10. 重新安装或升级 GitLab
如果问题仍未解决，可以尝试重新安装或升级 GitLab：

1. **备份数据：**
   ```bash
   sudo gitlab-rake gitlab:backup:create
   ```

2. **重新安装 GitLab：**
   ```bash
   sudo apt-get install --reinstall gitlab-ee
   ```

3. **升级 GitLab：**
   ```bash
   sudo apt-get update
   sudo apt-get install gitlab-ee
   ```

---

### 总结
HTTP 502 错误通常是由于 GitLab 服务未完全启动、配置错误或资源不足导致的。通过检查服务状态、日志文件、数据库连接和配置文件，可以逐步解决问题。

如果仍然无法解决，请提供具体的日志内容或错误信息，我可以进一步帮助你分析问题！

---

## 遇到错误二

Your account is pending approval from your GitLab administrator and hence blocked. Please contact your GitLab administrator if you think this is an error.

---

### 🤖 Assistant

当你在 GitLab 登录时看到以下提示：

> **Your account is pending approval from your GitLab administrator and hence blocked. Please contact your GitLab administrator if you think this is an error.**

这意味着你的 GitLab 账户正在等待管理员批准，或者管理员尚未激活你的账户。以下是解决该问题的步骤：

---

### 1. 确认 GitLab 的访问控制设置

1. **检查 GitLab 配置**  
   管理员需要确认 GitLab 的注册和访问控制设置是否配置正确。打开 `/etc/gitlab/gitlab.rb` 文件，检查以下配置：

   - **注册设置：**
     ```ruby
     gitlab_rails['gitlab_signup_enabled'] = true
     ```

   - **手动审批注册用户：**
     ```ruby
     gitlab_rails['require_admin_approval_after_user_signup'] = true
     ```

   如果 `require_admin_approval_after_user_signup` 设置为 `true`，则所有新注册用户都需要管理员手动批准。

2. **重新加载配置**  
   修改配置后，运行以下命令使更改生效：
   ```bash
   sudo gitlab-ctl reconfigure
   ```

---

### 2. 联系 GitLab 管理员

1. **找到管理员**  
   联系你的 GitLab 管理员，提供你的用户名和注册邮箱地址，请求他们批准你的账户。

2. **管理员批准账户**  
   管理员可以按照以下步骤批准你的账户：
   
   - 登录管理员账户。
   - 进入 **Admin Area**（管理员区域）。
   - 在左侧菜单中选择 **Users**（用户）。
   - 找到你的账户，点击 **Approve**（批准）按钮。

---

### 3. 检查账户状态

1. **查看账户状态**  
   如果你有管理员权限，可以运行以下命令检查账户状态：
   ```bash
   sudo gitlab-rails console
   ```

   在控制台中输入以下命令，查找你的账户：
   ```ruby
   user = User.find_by(username: 'your-username')
   user.state
   ```

   如果状态为 `blocked` 或 `pending_approval`，可以通过以下命令激活账户：
   ```ruby
   user.approve!
   user.activate!
   ```

2. **退出控制台**  
   输入 `exit` 退出控制台。

---

### 4. 检查电子邮件通知

1. **查看注册邮件**  
   注册时，GitLab 会发送一封确认邮件到你的注册邮箱。如果没有收到邮件，检查垃圾邮件文件夹，或者让管理员重新发送确认邮件。

2. **重新发送确认邮件**  
   管理员可以通过以下命令重新发送确认邮件：
   ```bash
   sudo gitlab-rails console
   ```

   在控制台中输入：
   ```ruby
   user = User.find_by(username: 'your-username')
   user.send_confirmation_instructions
   ```

---

### 5. 取消手动审批（可选）

如果不需要手动审批新用户，可以在 `/etc/gitlab/gitlab.rb` 中将 `require_admin_approval_after_user_signup` 设置为 `false`：

```ruby
gitlab_rails['require_admin_approval_after_user_signup'] = false
```

然后重新加载配置：
```bash
sudo gitlab-ctl reconfigure
```

---

### 总结

- 如果你的账户处于等待批准状态，请联系 GitLab 管理员批准你的账户。
- 检查 GitLab 的配置，确保注册和访问控制设置正确。
- 如果是管理员，可以通过控制台手动激活账户或重新发送确认邮件。

如果你有更多问题或需要进一步帮助，请随时提问！

---

## 如何登录管理员账户

---

### 🤖 Assistant

在刚安装完 GitLab 后，默认的管理员账户的用户名是 `root`，初始密码存储在服务器的一个文件中。以下是登录管理员账户的步骤：

---

### 1. 获取初始密码

1. **查找密码文件**  
   GitLab 在初次安装时会生成一个随机的初始密码，存储在以下文件中：
   ```
   /etc/gitlab/initial_root_password
   ```

2. **查看初始密码**  
   运行以下命令查看初始密码：
   ```bash
   sudo cat /etc/gitlab/initial_root_password
   ```

   你会看到类似如下的输出：
   ```
   Password: xxxxxxxxxxxxxxxxxxxxxxx
   ```

   其中 `xxxxxxxxxxxxxxxxxxxxxxx` 是初始密码。

3. **注意**  
   该文件会在首次 `gitlab-ctl reconfigure` 后 24 小时自动删除，因此请尽快登录并修改密码。

---

### 2. 登录管理员账户

1. **打开 GitLab 页面**  
   在浏览器中访问 GitLab 的 URL：
   ```
   http://your-gitlab-server-domain.com
   ```

2. **使用管理员账户登录**  
   - 用户名：`root`
   - 密码：上一步获取的初始密码

3. **修改密码**  
   首次登录后，GitLab 会要求你修改初始密码。按照提示设置一个新密码。

---

### 3. 设置管理员账户（可选）

如果你需要创建其他管理员账户，可以按照以下步骤操作：

1. **登录管理区域**  
   使用 `root` 账户登录后，点击页面右上角的用户图标，选择 **Admin Area**（管理员区域）。

2. **创建新用户**  
   - 在左侧菜单中选择 **Users**（用户）。
   - 点击 **New User**（新建用户）按钮。

3. **设置管理员权限**  
   - 在创建用户时，勾选 **Admin**（管理员）选项。
   - 填写其他信息并保存。

4. **激活账户**  
   新创建的用户需要激活账户。可以通过邮件确认或管理员手动激活。

---

### 4. 检查 GitLab 服务状态

如果无法登录，确保 GitLab 服务已正常运行：

1. **检查服务状态**  
   运行以下命令：
   ```bash
   sudo gitlab-ctl status
   ```

   确保所有服务（如 `nginx`、`unicorn`、`sidekiq`、`postgresql` 等）都正常运行。

2. **重启 GitLab**  
   如果有服务未启动，可以尝试重启 GitLab：
   ```bash
   sudo gitlab-ctl restart
   ```

3. **查看日志**  
   如果有问题，查看相关日志文件：
   - Nginx 日志：`/var/log/gitlab/nginx/error.log`
   - Unicorn 日志：`/var/log/gitlab/unicorn/unicorn_stderr.log`

---

### 总结

- 默认管理员账户的用户名是 `root`，初始密码存储在 `/etc/gitlab/initial_root_password` 文件中。
- 首次登录后，立即修改初始密码。
- 如果需要，可以创建其他管理员账户并分配权限。

如果仍有问题，请提供具体错误信息或日志内容，我将进一步帮助你解决问题！