import requests
import csv
from lxml import etree


# 创建我爱我家类
class Woaiwojia:
    # 创建页面获取函数
    def get_page(self, url):
        self.url = url
        user_agent="Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36"
        headers={"User-Agent":user_agent}  #请求头,headers是一个字典类型
        response = requests.get(self.url, headers=headers)
        print(response.text)
        return response.text
    # 创建解析函数
    def parse_page(self, url):
        self.url = url
        selector = etree.HTML(self.get_page(self.url))
        
        items = selector.xpath('/html/body/div[6]/div[1]/div[2]/ul//li')
        #print("123")
        print(items)
        for item in items:
            
            Action = item.xpath('./div[2]/div[1]/p[3]/text()')[0]
            Url = item.xpath('/html/body/div[6]/div[1]/div[2]/ul/li[1]/div[2]/h3/a')[0]
            print(123)
            info = [Action, Url]
            print(info[0])
            #self.csv_info(info)
    # 创建保存函数
    def csv_info(self, content):
        with open('info.csv', 'a', encoding='utf-8', newline='')as file:
            write = csv.writer(file)
            write.writerow(content)
# 调用运行
if __name__ == '__main__':
    k = Woaiwojia()
    title = ['名称', '户型', '地区', '售价', '总价/万']
    k.csv_info(title)
    url = 'https://hz.5i5j.com/ershoufang/_%E4%B8%B4%E5%B9%B3/'
    k.parse_page(url)
    for x in range(2, 3):
        url = 'https://hz.5i5j.com/ershoufang/n{}/_%E4%B8%B4%E5%B9%B3/'.format(x)
        k.parse_page(url)