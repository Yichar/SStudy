# coding=utf-8
import requests
import csv
from lxml import etree
# 创建我爱我家类
class Woaiwojia:
    # 创建页面获取函数
    def get_page(self, url):
        self.url = url
        headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/',
        '537.36 (KHTML, like Gecko) Chrome/72.0.3626.81 Safari/537.36'
        }

        response = requests.get(self.url, headers=headers)
        return response.text
